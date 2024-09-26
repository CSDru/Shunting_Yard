//
// Created by Dru on 9/26/2024.
//

#ifndef SHUNTING_YARD_QUEUE_CPP
#define SHUNTING_YARD_QUEUE_CPP
#include "Queue.h"

template<typename T>
void Queue<T>::push(const T &data)
{
    list.push_back(data);
}

template<typename T>
void Queue<T>::pop()
{
    if(!isEmpty())
        list.pop_front();
    else
        throw std::out_of_range("Queue is empty");
}

template<typename T>
T &Queue<T>::top()
{
    if(!isEmpty())
        return list.front();
    else
        throw std::out_of_range("Queue is empty");
}

template<typename T>
const T &Queue<T>::top() const
{
    if(!isEmpty())
        return list.front();
    else
        throw std::out_of_range("Queue is empty");
}

template<typename T>
bool Queue<T>::isEmpty() const
{
    return list.empty();
}

template<typename T>
int Queue<T>::size() const
{
    return list.size();
}

#endif //SHUNTING_YARD_QUEUE_CPP