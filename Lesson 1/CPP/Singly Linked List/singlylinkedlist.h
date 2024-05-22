#ifndef SINGLYLINKEDLIST_H
#define SINGLYLINKEDLIST_H

#include <iostream>

struct Node {
    int data;
    Node* next;
    Node(int value) : data(value), next(nullptr) {}
};

class SinglyLinkedList {
private:
    Node* head;
    int size;

public:
    SinglyLinkedList();
    ~SinglyLinkedList();
    int getSize() const;
    void addFirst(int value);
    void addLast(int value);
    void addAt(int index, int value);
    void removeFirst();
    void removeLast();
    void removeAt(int index);
    void print() const;
    void clear();
};

#endif // SINGLYLINKEDLIST_H
