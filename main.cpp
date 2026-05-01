#include <iostream>
#include <vector>
#include <string>
#include <cctype>
#include <unordered_map>

#include "ArrayStack.h"

using namespace std;

// token

struct Token {
    string value;   // number or operator
};

// tokenizer

vector<Token> tokenize(const string& line) {
    vector<Token> tokens;
    string currentNum = ""; // build number
    for (int i = 0; i < line.length(); i++) {
        char c = line[i];
        if (isdigit(c)) {
            currentNum += c; // add digit
        }
        else {
            if (!currentNum.empty()) {
                tokens.push_back({currentNum}); // push number
                currentNum = "";
            }
            if (isspace(c)) {
                continue; // skip space
            }
            if (c == '+' || c == '-' || c == '*' || c == '/' || c == '(' || c == ')') {
                string tokenValue = "";
                tokenValue += c;
                tokens.push_back({tokenValue}); // push op
            }
            else {
                string tokenValue = "";
                tokenValue += c;
                tokens.push_back({tokenValue}); // invalid char
            }
        }
    }
    if (!currentNum.empty()) {
        tokens.push_back({currentNum}); // last number
    }
    return tokens;
}

// helpers

bool isOperator(const string& s) {
    return s == "+" || s == "-" || s == "*" || s == "/";
}

int precedence(const string& op) {
    if (op == "+" || op == "-") {
        return 1; // low
    }
    if (op == "*" || op == "/") {
        return 2; // high
    }
    return 0;
}

// detection

bool isValidPostfix(const vector<Token>& tokens) {
    int stackDepth = 0; // fake stack
    if (tokens.empty()) {
        return false;
    }
    for (int i = 0; i < tokens.size(); i++) {
        string value = tokens[i].value;
        if (isdigit(value[0])) {
            stackDepth++; // push
        }
        else if (isOperator(value)) {
            if (stackDepth < 2) {
                return false; // not enough nums
            }
            stackDepth--; // combine
        }
        else {
            return false;
        }
    }
    return stackDepth == 1; // one result
}

bool isValidInfix(const vector<Token>& tokens) {
    if (tokens.empty()) {
        return false;
    }
    ArrayStack<string> parenthesis; // track ()
    bool numOrLeftParenthesis = true; // expect num
    for (int i = 0; i < tokens.size(); i++) {
        string value = tokens[i].value;
        if (isdigit(value[0])) {
            if (!numOrLeftParenthesis) {
                return false;
            }
            numOrLeftParenthesis = false;
        }
        else if (value == "(") {
            if (!numOrLeftParenthesis) {
                return false;
            }
            parenthesis.push(value);
            numOrLeftParenthesis = true;
        }
        else if (value == ")") {
            if (numOrLeftParenthesis) {
                return false;
            }
            if (parenthesis.empty()) {
                return false;
            }
            parenthesis.pop();
            numOrLeftParenthesis = false;
        }
        else if (isOperator(value)) {
            if (numOrLeftParenthesis) {
                return false;
            }
            numOrLeftParenthesis = true;
        }
        else {
            return false;
        }
    }
    return !numOrLeftParenthesis && parenthesis.empty(); // valid end
}

// conversion

vector<Token> infixToPostfix(const vector<Token>& tokens) {
    vector<Token> output;
    ArrayStack<Token> stack; // operator stack
    for (int i = 0; i < tokens.size(); i++) {
        string value = tokens[i].value;
        if (isdigit(value[0])) {
            output.push_back(tokens[i]); // number out
        }
        else if (value == "(") {
            stack.push(tokens[i]); // push (
        }
        else if (value == ")") {
            while (!stack.empty() && stack.top().value != "(") {
                output.push_back(stack.top()); // pop ops
                stack.pop();
            }
            if (!stack.empty()) {
                stack.pop(); // remove (
            }
        }
        else if (isOperator(value)) {
            while (!stack.empty() && isOperator(stack.top().value) && precedence(stack.top().value) >= precedence(value)) {
                output.push_back(stack.top()); // pop higher
                stack.pop();
            }
            stack.push(tokens[i]); // push op
        }
    }
    while (!stack.empty()) {
        output.push_back(stack.top()); // remaining ops
        stack.pop();
    }
    return output;
}

// evaluation

double evalPostfix(const vector<Token>& tokens) {
    ArrayStack<double> stack; // number stack
    for (int i = 0; i < tokens.size(); i++) {
        string value = tokens[i].value;
        if (isdigit(value[0])) {
            stack.push(stod(value)); // push num
        }
        else if (isOperator(value)) {
            double right = stack.top();
            stack.pop();
            double left = stack.top();
            stack.pop();
            double result = 0;
            if (value == "+") {
                result = left + right;
            }
            else if (value == "-") {
                result = left - right;
            }
            else if (value == "*") {
                result = left * right;
            }
            else if (value == "/") {
                result = left / right;
            }
            stack.push(result); // push result
        }
    }
    return stack.top(); // final answer
}

// main

int main() {
    string line;
    getline(cin, line);

    vector<Token> tokens = tokenize(line);

    if (isValidPostfix(tokens)) {
        cout << "FORMAT: POSTFIX\n";
        cout << "RESULT: " << evalPostfix(tokens) << "\n";
    }
    else if (isValidInfix(tokens)) {
        vector<Token> postfix = infixToPostfix(tokens);
        cout << "FORMAT: INFIX\n";
        cout << "POSTFIX: ";
        for (const auto& t : postfix) {
            cout << t.value << " ";
        }
        cout << "\n";
        cout << "RESULT: " << evalPostfix(postfix) << "\n";
    }
    else {
        cout << "FORMAT: NEITHER\n";
        cout << "ERROR: invalid expression\n";
    }

    return 0;
}