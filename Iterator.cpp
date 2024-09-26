//
// Created by Dru on 9/26/2024.
//

#include "Iterator.h"

template<typename T>
Iterator<T>::Iterator(Node<T> *start) : current(start){}

template<typename T>
T &Iterator<T>::operator*()
{
    if(current)
        return current->data;
    else
        throw std::out_of_range("Dereferencing a null iterator");
}

template<typename T>
Iterator<T> &Iterator<T>::operator++()
{
    if(current)
        current = current->next;
    return *this;
}

template<typename T>
Iterator<T> Iterator<T>::operator++(int)
{
    Iterator temp = *this;
    ++(*this);
    return temp;
}

template<typename T>
bool Iterator<T>::operator!=(const Iterator &other) const
{
    return current != other.current;
}