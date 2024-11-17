#ifndef STACK_H
#define STACK_H

#include <vector>
#include <stdexcept>
#include <iostream>

template <class T>
class Stack {
private:
    std::vector<T> elements;

public:
    void push(const T& value);     // Adds an element to the top of the stack
    T pop();                       // Removes and returns the top element of the stack
    T top() const;                 // Returns the top element without removing it
    void clear();                  // Clears the stack
    bool empty() const;            // Checks if the stack is empty
};

// Adds an element to the top of the stack
template <class T>
void Stack<T>::push(const T& value) {
    elements.push_back(value);
}

// Removes and returns the top element of the stack
template <class T>
T Stack<T>::pop() {
    if (elements.empty()) throw std::runtime_error("Stack underflow: No elements to pop.");
    T value = elements.back();
    elements.pop_back();
    return value;
}

// Returns the top element without removing it
template <class T>
T Stack<T>::top() const {
    if (elements.empty()) throw std::runtime_error("Stack is empty: No top element.");
    return elements.back();
}

// Clears the stack
template <class T>
void Stack<T>::clear() {
    elements.clear();
}

// Checks if the stack is empty
template <class T>
bool Stack<T>::empty() const {
    return elements.empty();
}

#endif // STACK_H
