#pragma once
#ifndef LIST_HPP
#define LIST_HPP

#include <stdexcept>
#include <iostream>

template<typename E>
class Node {
    E data;
    Node* next;

    Node(const T& value) : data(value), next(nullptr) {}
};

template<typename E>
class List {
    private:
        Node<E>* head;
        int size;

    public:
        List() :head(nullptr), size(0) {}
        ~List() { clear(); }

        int push_back(const T& value) {
            
        }
};

#endif