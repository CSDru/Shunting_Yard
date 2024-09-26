//
// Created by Dru on 9/26/2024.
//

#ifndef SHUNTING_YARD_STACK_CPP
#define SHUNTING_YARD_STACK_CPP

#include "Stack.h"

template<typename T>
void Stack<T>::push(const T &data)
{
    list.push_front(data);
}

template<typename T>
void Stack<T>::pop()
{
    if(!isEmpty())
        list.pop_front();
    else
        throw std::out_of_range("Stack is empty");
}

template<typename T>
T &Stack<T>::top()
{
    if(!isEmpty())
        return list.front();
    else
        throw std::out_of_range("Stack is empty");
}

template<typename T>
const T &Stack<T>::top() const
{
    if(!isEmpty())
        return list.front();
    else
        throw std::out_of_range("Stack is empty");
}

template<typename T>
bool Stack<T>::isEmpty() const
{
    return list.empty();
}

template<typename T>
int Stack<T>::size() const
{
    return list.size();
}

#endif //SHUNTING_YARD_STACK_CPP