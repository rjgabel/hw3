#ifndef STACK_H
#define STACK_H

#include <stdexcept>
#include <vector>

// Use inheritance from std::vector (choose public/private) as appropriate
template <typename T> class Stack : private std::vector<T> {
  public:
    Stack(){};
    ~Stack(){};
    bool empty() const { return std::vector<T>::empty(); };
    size_t size() const { return std::vector<T>::size(); };
    void push(const T& item) { this->push_back(item); };
    void pop() {
        if (empty()) {
            throw std::underflow_error("");
        } else {
            this->pop_back();
        }
    }; // throws std::underflow_error if empty
    const T& top() const {
        if (empty()) {
            throw std::underflow_error("");
        } else {
            return (*this)[size() - 1];
        }
    }; // throws std::underflow_error if empty
    // Add other members only if necessary
};

#endif