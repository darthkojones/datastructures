#include "SinglyLinkedList.h"

SinglyLinkedList::SinglyLinkedList() : head(nullptr), size(0) {}

SinglyLinkedList::~SinglyLinkedList() {
    clear();
}

int SinglyLinkedList::getSize() const {
    return size;
}

void SinglyLinkedList::addFirst(int value) {
    Node* newNode = new Node(value);
    newNode->next = head;
    head = newNode;
    size++;
}

void SinglyLinkedList::addLast(int value) {
    Node* newNode = new Node(value);
    if (!head) {
        head = newNode;
    } else {
        Node* temp = head;
        while (temp->next) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
    size++;
}

void SinglyLinkedList::addAt(int index, int value) {
    if (index < 0 || index > size) {
        std::cerr << "Index out of bounds" << std::endl;
        return;
    }
    if (index == 0) {
        addFirst(value);
    } else {
        Node* newNode = new Node(value);
        Node* temp = head;
        for (int i = 0; i < index - 1; i++) {
            temp = temp->next;
        }
        newNode->next = temp->next;
        temp->next = newNode;
        size++;
    }
}

void SinglyLinkedList::removeFirst() {
    if (!head) {
        std::cerr << "List is empty" << std::endl;
        return;
    }
    Node* temp = head;
    head = head->next;
    delete temp;
    size--;
}

void SinglyLinkedList::removeLast() {
    if (!head) {
        std::cerr << "List is empty" << std::endl;
        return;
    }
    if (!head->next) {
        delete head;
        head = nullptr;
    } else {
        Node* temp = head;
        while (temp->next->next) {
            temp = temp->next;
        }
        delete temp->next;
        temp->next = nullptr;
    }
    size--;
}

void SinglyLinkedList::removeAt(int index) {
    if (index < 0 || index >= size) {
        std::cerr << "Index out of bounds" << std::endl;
        return;
    }
    if (index == 0) {
        removeFirst();
    } else {
        Node* temp = head;
        for (int i = 0; i < index - 1; i++) {
            temp = temp->next;
        }
        Node* nodeToDelete = temp->next;
        temp->next = temp->next->next;
        delete nodeToDelete;
        size--;
    }
}

void SinglyLinkedList::print() const {
    Node* temp = head;
    while (temp) {
        std::cout << temp->data << " ";
        temp = temp->next;
    }
    std::cout << std::endl;
    std::cout << "Size: " << size << std::endl;
}

void SinglyLinkedList::clear() {
    while (head) {
        removeFirst();
    }
}
