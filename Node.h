//
// Created by Dru on 9/24/2024.
//

#ifndef LINKED_LIST_NODE_H
#define LINKED_LIST_NODE_H

template <typename T>

struct Node
{
    T data;
    Node<T> *next = nullptr, *prev = nullptr;

    explicit Node(const T& value) : data(value) {}

    Node() : data(T()){}
};

#endif //LINKED_LIST_NODE_H
