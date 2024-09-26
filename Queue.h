//
// Created by Dru on 9/26/2024.
//

#ifndef SHUNTING_YARD_QUEUE_H
#define SHUNTING_YARD_QUEUE_H
#include "LinkedList.h"

template <typename T>
class Queue
{
private:
    LinkedList<T> list;

public:
    Queue() = default;

    void push(const T& data);
    void pop();
    T& top();
    const T& top() const;
    bool isEmpty() const;
    int size() const;
};

#include "Queue.cpp"
#endif //SHUNTING_YARD_QUEUE_H
