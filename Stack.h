//
// Created by Dru on 9/26/2024.
//

#ifndef SHUNTING_YARD_STACK_H
#define SHUNTING_YARD_STACK_H

#include "LinkedList.h"

template <typename T>
class Stack
{
private:
    LinkedList<T> list;

public:
    Stack() = default;

    void push(const T& data);
    void pop();
    T& top();
    const T& top() const;
    bool isEmpty() const;
    int size() const;
};

#include "Stack.cpp"
#endif //SHUNTING_YARD_STACK_H
