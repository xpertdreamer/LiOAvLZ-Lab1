#pragma once
#ifndef LIST_HPP
#define LIST_HPP

#include <stdexcept>
#include <iostream>

template<typename E>
class List;

template<typename E>
class Node {
    E data;
    Node* next;

    explicit Node(const E& value) : data(value), next(nullptr) {}
    friend class List<E>;
};

template<typename E>
class List {
    Node<E>* head;
    int size;

    public:
        List() :head(nullptr), size(0) {}
        ~List() { clear(); }

        [[nodiscard]] int get_size() const { return size; }

        void insert(const E &value, int position) {
            if (position < 0 || position > size) return;

            auto *newNode = new Node<E>(value);

            if (position == 0) {
                newNode->next = head;
                head = newNode;
            } else {
                auto *curr = head;
                for (int i = 0; i < position - 1; i++) {
                    curr = curr->next;
                }

                newNode->next = curr->next;
                curr->next = newNode;
            }
            size++;
        }

        void remove(const int position) {
            if (position < 0 || position > size || head == nullptr) throw std::out_of_range("Out of bounds");

            Node<E>* temp;

            if (position == 0) {
                temp = head;
                head = head->next;
            } else {
                auto curr = head;
                for (int i = 0; i < position - 1; i++) curr = curr->next;
                temp = curr->next;
                curr->next = temp->next;
            }

            delete temp;
            size--;
        }

        E& at(const int index) const {
            if (index < 0 || index >= size || head == nullptr) throw std::out_of_range("Out of bounds");

            auto curr = head;
            for (int i = 0; i < index; i++) curr = curr->next;

            return curr->data;
        }

        void push_back(const E& value) {
            auto* newNode = new Node<E>(value);

            if (head == nullptr) head = newNode;
            else {
                auto* curr = head;
                while (curr->next != nullptr) curr = curr->next;
                curr->next = newNode;
            }
            size++;
        }

        void clear() {
            while (head != nullptr) {
                auto* temp = head;
                head = head->next;
                delete temp;
            }
            size = 0;
        }

        [[nodiscard]] bool is_empty() const {
            return head == nullptr;
        }
};

#endif