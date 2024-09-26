//
// Created by Dru on 9/24/2024.
//

#ifndef LINKED_LIST_LINKEDLIST_H
#define LINKED_LIST_LINKEDLIST_H
#include "Node.h"
#include <initializer_list>
#include <iostream>

template <typename T>
class LinkedList
{
private:
    Node<T>* head = nullptr, *tail = nullptr;
    int _size = 0;
    void push_front(Node<T>* node);
    void push_back(Node<T>* node);

    void one_node_pop();
    void remove(Node<T>* target);
    void clear();

    void insert_before(Node<T>* target, Node<T>* node);
    void insert_after(Node<T>* target, Node<T>* node);
    Node<T>* search(const T& target);
    Node<T>* createNode(const T& data);
public:
    LinkedList();
    LinkedList(const std::initializer_list<T>& list);

    LinkedList(const LinkedList<T>& list);

    ~LinkedList();

    LinkedList<T>& operator=(const LinkedList<T>& list);

    template<typename U>
    friend std::ostream& operator<<(std::ostream& out, const LinkedList<U>& list);
    template <typename U>
    friend LinkedList<U> operator+(const LinkedList<U>& list1, const LinkedList<U>& list2);

    int size() const;
    void push_front(const T& data);
    void push_back(const T& data);
    void pop_front();
    void pop_back();

    T& front(); ///return data from head
    T& back(); ///return data from tail
    const T& front() const; ///return data from head
    const T& back() const; ///return data from head

    bool empty() const;

    bool contains(const T& data);

    void remove(const T& data); ///remove the first instance of data
    void insert_before(const T& targetData, const T& newData);
    void insert_after(const T& targetData, const T& newData);
};

#include "LinkedList.cpp"
#endif //LINKED_LIST_LINKEDLIST_H
