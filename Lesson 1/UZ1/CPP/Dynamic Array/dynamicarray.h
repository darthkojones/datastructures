#ifndef DYNAMICARRAY_H
#define DYNAMICARRAY_H

#include <iostream>

class DynamicArray {
private:
    int *array;
    int capacity;
    int size;

    void resize(int newCapacity);

public:
    DynamicArray();
    ~DynamicArray();
    int getSize() const;
    void add(int value);
    void addAt(int index, int value);
    int get(int index) const;
    void print() const;
};

#endif // DYNAMICARRAY_H
