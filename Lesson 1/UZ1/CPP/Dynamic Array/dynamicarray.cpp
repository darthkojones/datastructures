#include "DynamicArray.h"

DynamicArray::DynamicArray() {
    capacity = 10;
    size = 0;
    array = new int[capacity];
}

DynamicArray::~DynamicArray() {
    delete[] array;
}

void DynamicArray::resize(int newCapacity) {
    int *newArray = new int[newCapacity];
    for (int i = 0; i < size; i++) {
        newArray[i] = array[i];
    }
    delete[] array;
    array = newArray;
    capacity = newCapacity;
}

int DynamicArray::getSize() const {
    return size;
}

void DynamicArray::add(int value) {
    if (size == capacity) {
        resize(capacity * 2);
    }
    array[size++] = value;
}

void DynamicArray::addAt(int index, int value) {
    if (index < 0 || index >= capacity) {
        if (index >= capacity) {
            resize(index + 1);
        } else {
            std::cerr << "Index out of bounds" << std::endl;
            return;
        }
    }
    if (index >= size) {
        size = index + 1;
    }
    array[index] = value;
}

int DynamicArray::get(int index) const {
    if (index < 0 || index >= size) {
        std::cerr << "Index out of bounds" << std::endl;
        return -1;
    }
    return array[index];
}

void DynamicArray::print() const {
    for (int i = 0; i < size; i++) {
        std::cout << array[i] << " ";
    }
    std::cout << std::endl;
    std::cout << "Size: " << size << std::endl;
}
