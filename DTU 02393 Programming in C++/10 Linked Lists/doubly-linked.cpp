#include "doubly-linked.h"
#include <iostream>

using namespace std;

List::List(void){
    first=nullptr;
    return;
}

List::~List(void){
    Node * currentNode = first;
    Node * nextNode = nullptr;
    while(currentNode != nullptr){

        // store next node.
        nextNode = currentNode -> next;
        delete currentNode;

        // move pointer one position ahead.
        currentNode = nextNode;
    }
}

void List:: insert(int n){
    Node * newNode = new Node;

    // if list is empty.
    if(first==nullptr){
        first = newNode;

        // link new node as start node
        newNode -> prev = nullptr;
    }

    // else iterate through list until end is reached.
    else
    {
        Node * currentNode  = first;
        Node * prevNode = nullptr;
        Node * nextNode = nullptr;
        while (currentNode != nullptr)
        {
            // store next and previous
            nextNode = currentNode -> next;
            prevNode = currentNode;

            // move pointer on position ahead
            currentNode = nextNode;
        }

        // link new node as end node
        prevNode -> next = newNode;
        newNode -> prev = prevNode;
    }

    // common operations to link new node
    newNode -> next = nullptr;
    newNode -> val = n;
}

void List::reverse(void)
{
    // Initialize current, previous and
    // next pointers
    Node * currentNode = first;
    Node * prevNode = nullptr;
    Node * nextNode = nullptr;

    while (currentNode != nullptr) {
        // Store next
        nextNode = currentNode->next;

        // Reverse current node's pointer
        currentNode->next = prevNode;

        // Move pointers one position ahead.
        prevNode = currentNode;
        currentNode = nextNode;
    }
    // When nullptr is reached define previous node as start of linked list.
    first = prevNode;
}

void List::print(void){
    Node * currentNode  = first;
    Node * nextNode = nullptr;
    while(currentNode != nullptr){
        // Store next.
        nextNode = currentNode -> next;
        // Print current node value.
        cout << currentNode-> val << " ";
        // Move pointer on position ahead.
        currentNode = nextNode;
    }
    cout << endl;
}