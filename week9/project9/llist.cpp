#include "llist.h"
#include <iostream>
#include <format>


// Walks the list and returns the node at the end
Node *getLastNode(Node *head){
    if (head == nullptr) {return nullptr;}
    Node *currNode = head;
    while(currNode->next != nullptr){
        currNode = currNode->next;
    }

    return currNode;
}

void LinkedList::push(int val){
    Node *n = new Node(val);
    n->next = head;
    head = n;
}


void LinkedList::pop(){
    if(head == nullptr){
        return;
    }

    Node *oldHead = head;
    head = head->next;
    delete oldHead;

}

void LinkedList::pushback(int val){
    Node *currNode = getLastNode(head);
    if(currNode == nullptr){
        head = new Node(val);
        return;
    }

    currNode->next = new Node(val);
}

void LinkedList::popback(){
    if(head == nullptr){return;}
    if(head->next == nullptr){
        delete head;
        head = nullptr;
        return;
    }

    Node *secondToLastNode = head;
    while(secondToLastNode->next->next != nullptr){
        secondToLastNode = secondToLastNode->next;
    }

    delete secondToLastNode->next;
    secondToLastNode-> next = nullptr;

}

void LinkedList::del(int val){
    if(head == nullptr){return;}
    Node *currNode = head;
    Node *last = nullptr;
    while(currNode != nullptr){
        if(currNode->data == val){
            if(last != nullptr){
                last->next = currNode->next;
            }
            else {
                head = currNode->next;
            }
            delete currNode;
            return;
        }
        last = currNode;
        currNode = currNode->next;
    }

}

void LinkedList::print(){
    if(head == nullptr){
        std::cout << "[EMPTY]\n";
        return;
    }

    Node *currNode = head;
    std::cout << std::format("({})", currNode->data);
    currNode = currNode->next;
    while(currNode != nullptr){
        std::cout << std::format("->({})", currNode->data);
        currNode = currNode->next;
    }
    std::cout << '\n';
}
