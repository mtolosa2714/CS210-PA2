#ifndef ARRAYSTACK_H
#define ARRAYSTACK_H

#include <vector>
#include <stdexcept>

template <typename T>
class ArrayStack {
private:
    std::vector<T> data;

public:
    void push(const T& value) {
        // TODO
        //add an element to the stack
        data.push_back(value);
    }

    void pop() {
        // TODO
        //remove the top element
        if (empty()) {
            throw std::out_of_range("Stack is empty");
        }
        data.pop_back();
    }

    T top() const {
        // TODO
        //return the top element
        if (empty()) {
            throw std::out_of_range("Stack is empty");
        }
        return data.back();
    }

    bool empty() const {
        // TODO
        //check if stack is empty
        return data.empty();
    }

    int size() const {
        // TODO
        //return number of items
        return data.size();
    }
};

#endif
