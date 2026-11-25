#pragma once

#include <iostream>

class Node {
    public:
        int data;
        Node *next;
        Node(int data): data(data), next(nullptr) {};
        ~Node() = default;

};

class LinkedList {
    Node *head;
    public:
        LinkedList(): head(nullptr) {};
        ~LinkedList() {
            Node *curr = head;
            while(curr != nullptr){
                Node *next = curr->next;
                delete curr;
                curr = next;
            }
        }
        LinkedList(const LinkedList&) = delete;
        LinkedList& operator=(const LinkedList& other) = delete;

        void push(int val);
        void pop();
        void pushback(int val);
        void popback();
        void del(int val);
        void print();

};