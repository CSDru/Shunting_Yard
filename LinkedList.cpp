//
// Created by Dru on 9/24/2024.
//
#ifndef LINKED_LIST_LINKEDLIST_CPP
#define LINKED_LIST_LINKEDLIST_CPP
#include "LinkedList.h"

template<typename T>
void LinkedList<T>::push_front(Node<T> *node)
{
    if(empty())
    {
        head = node;
        tail = node;
    }
    else
    {
        node->next = head;
        head->prev = node;
        head = node;
    }
}

template<typename T>
void LinkedList<T>::push_back(Node<T> *node)
{
    if(empty())
    {
        head = node;
        tail = node;
    }
    else
    {
        tail->next = node;
        node->prev = tail;
        tail = node;
    }
}

template<typename T>
void LinkedList<T>::one_node_pop()
{
    if(head)
    {
        delete head;
        head = nullptr;
        tail = nullptr;
    }
}

template<typename T>
void LinkedList<T>::remove(Node<T>* target)
{
    // If the list is empty or target is nullptr, do nothing
    if (empty() || target == nullptr) return;

    if(head == tail)
    {
        one_node_pop();
        return;
    }

    // Case 1: Removing the head
    if (target == head)
    {
        pop_front();
        return;
    }

    // Case 2: Removing the tail
    else if (target == tail)
    {
        pop_back();
        return;
    }

    // Case 3: Removing a node in the middle
    else
    {
        target->prev->next = target->next;
        target->next->prev = target->prev;
        delete target;
    }
}


template<typename T>
void LinkedList<T>::clear()
{
    while(head)
        remove(head);
}

template<typename T>
void LinkedList<T>::insert_before(Node<T> *target, Node<T> *node)
{
    // Case 1: The target is at the front of the list
    if(target == head)
        push_front(node);

    // Case 2: The target is in the middle or end of the list
    else
    {
        target->prev->next = node;
        node->prev = target->prev;
        node->next = target;
        target->prev = node;
    }
}

template<typename T>
void LinkedList<T>::insert_after(Node<T> *target, Node<T> *node)
{
    // Case 1: The target is at the back of the list
    if(target == tail)
        push_back(node);

        // Case 2: The target is in the middle or end of the list
    else
    {
        target->next->prev = node;
        node->next = target->next;
        node->prev = target;
        target->next = node;
    }
}

template<typename T>
Node<T> *LinkedList<T>::search(const T &target)
{
    for(Node<T>* current = head; current; current = current->next)
    {
        if(current->data == target)
            return current;
    }
    return nullptr;
}

template<typename T>
Node<T> *LinkedList<T>::createNode(const T &data)
{
    auto* node = new Node<T>;
    node->data = data;
    return node;
}

template<typename T>
LinkedList<T>::LinkedList()
= default;

template<typename T>
LinkedList<T>::LinkedList(const std::initializer_list<T> &list)
{
    for(const T& data : list)
        push_back(new Node<T>(data));
}

template<typename T>
LinkedList<T>::LinkedList(const LinkedList<T> &list)
{
    for(Node<T>* current = list.head; current; current = current->next)
        push_back(new Node<T>(current->data));
}

template<typename T>
LinkedList<T>::~LinkedList()
{
    clear();
}

template<typename T>
LinkedList<T> &LinkedList<T>::operator=(const LinkedList<T> &list)
{
    if (this == &list)
        return *this;

    clear();

    for(Node<T>* current = list.head; current; current = current->next)
        push_back(new Node<T>(current->data));

    return *this;
}

template<typename T>
int LinkedList<T>::size() const
{
    int count = 0;
    for(Node<T>* current = head; current; current = current->next)
        ++count;
    return count;
}

template<typename T>
void LinkedList<T>::push_front(const T &data)
{
    auto* node = new Node<T>(data);
    push_front(node);
}

template<typename T>
void LinkedList<T>::push_back(const T &data)
{
    auto* node = new Node<T>(data);
    push_back(node);
}

template<typename T>
void LinkedList<T>::pop_front()
{
    if(head == nullptr)
        return;

    if(head == tail)
        one_node_pop();

    else
    {
        Node<T>* temp = head;
        head = head->next;
        head->prev = nullptr;
        delete temp;
    }
}

template<typename T>
void LinkedList<T>::pop_back()
{
    if(tail == nullptr)
        return;

    if(head == tail)
        one_node_pop();

    else
    {
        Node<T>* temp = tail;
        tail = tail->prev;
        tail->next = nullptr;
        delete temp;
    }
}

template<typename T>
T &LinkedList<T>::front()
{
    if(empty())
        throw std::out_of_range("The List is empty");

    return head->data;
}

template<typename T>
T &LinkedList<T>::back()
{
    if(empty())
        throw std::out_of_range("The List is empty");

    return tail->data;
}

template<typename T>
const T &LinkedList<T>::front() const
{
    if(empty())
        throw std::out_of_range("The List is empty");

    return head->data;
}

template<typename T>
const T &LinkedList<T>::back() const
{
    if(empty())
        throw std::out_of_range("The List is empty");

    return tail->data;
}

template<typename T>
bool LinkedList<T>::empty() const
{
    if(head == nullptr && tail == nullptr)
        return true;

    return false;
}

template<typename T>
bool LinkedList<T>::contains(const T &data)
{
    if(search(data))
        return true;
    return false;
}

template<typename T>
void LinkedList<T>::remove(const T &data)
{
    remove(search(data));
}

template<typename T>
void LinkedList<T>::insert_before(const T &targetData, const T &newData)
{
    Node<T>* targetNode = search(targetData);

    if(targetNode == nullptr)
        throw std::invalid_argument("Target data not found in the list.");

    insert_before(targetNode, new Node<T>(newData));
}

template<typename T>
void LinkedList<T>::insert_after(const T &targetData, const T &newData)
{
    Node<T>* targetNode = search(targetData);

    if(targetNode == nullptr)
        throw std::invalid_argument("Target data not found in the list.");

    insert_after(targetNode, new Node<T>(newData));
}

template<typename U>
std::ostream &operator<<(std::ostream &out, const LinkedList<U> &list)
{
    out << "[";
    for(Node<U>* current = list.head; current; current = current->next)
    {
        out << current->data;
        if (current->next)
            out << ", ";
    }
    out << "]";
    return out;
}

template<typename U>
LinkedList<U> operator+(const LinkedList<U> &list1, const LinkedList<U> &list2)
{
    LinkedList<U> result;
    for (Node<U>* current = list1.head; current; current = current->next)
        result.push_back(current->data);
    for (Node<U>* current = list2.head; current; current = current->next)
        result.push_back(current->data);
    return result;
}

#endif