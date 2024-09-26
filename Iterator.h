//
// Created by Dru on 9/26/2024.
//

#ifndef SHUNTING_YARD_ITERATOR_H
#define SHUNTING_YARD_ITERATOR_H

#include "Node.h"
#include <stdexcept>


template <typename T>
class Iterator
{
private:
    Node<T>* current;

public:
    Iterator(Node<T>* start);

    // Overloaded operators
    T& operator*();                   // Dereference operator
    Iterator& operator++();           // Prefix increment
    Iterator operator++(int);         // Postfix increment
    bool operator!=(const Iterator& other) const; // Inequality operator
};

#endif //SHUNTING_YARD_ITERATOR_H
