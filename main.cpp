#include <iostream>
#include <vector>
#include <string>
#include <cctype>
#include <unordered_map>

#include "ArrayStack.h"

using namespace std;

// Token

struct Token {
    string value;   // number, operator, or parenthesis
};

// Tokenizer

vector<Token> tokenize(const string& line) {
    vector<Token> tokens;
    // TODO
    string currentNum = "";
    for (int i = 0; i < line.length(); i++) {
        char c = line[i];
        if (isdigit(c)) {
            currentNum += c;
        }
        else {
            if (!currentNum.empty()) {
                tokens.push_back(Token(currentNum));
                currentNum = "";
            }
            if (isspace(c)) {
                continue;
            }
            if (c == '+' || c == '-' || c == '*' || c == '/' || c == '(' || c == ')') {
                string tokenValue = "";
                tokenValue += c;
                tokens.push_back({tokenValue});
            }
            else {
                string tokenValue = "";
                tokenValue += c;
                tokens.push_back({tokenValue});
            }
        }
    }
    return tokens;
}

// Helpers

bool isOperator(const string& s) {
    return s == "+" || s == "-" || s == "*" || s == "/";
}

int precedence(const string& op) {
    // TODO
    if (op == "+" || op == "-") {
        return 1;
    }
    if (op == "*" || op == "/") {
        return 2;
    }
    return 0;
}

// Detection

bool isValidPostfix(const vector<Token>& tokens) {
    // TODO
    int stackDepth = 0;
    if (tokens.empty()) {
        return false;
    }
    for (int i = 0; i < tokens.size(); i++) {
        string value = tokens[i].value;
        if (isdigit(value[0])) {
            stackDepth++;
        }
        else if (isOperator(value)) {
            if (stackDepth < 2) {
                return false;
            }
            stackDepth--;
        }
        else {
            return false;
        }
    }
    return stackDepth == 1;
}

bool isValidInfix(const vector<Token>& tokens) {
    // TODO
    return false;
}

// Conversion

vector<Token> infixToPostfix(const vector<Token>& tokens) {
    vector<Token> output;
    // TODO
    return output;
}

// Evaluation

double evalPostfix(const vector<Token>& tokens) {
    ArrayStack<double> stack;
    // TODO
    return 0.0;
}

// Main

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
