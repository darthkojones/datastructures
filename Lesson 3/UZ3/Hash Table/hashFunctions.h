#ifndef HASHFUNCTIONS_H
#define HASHFUNCTIONS_H

#include <string>

int hashFunction1(const std::string& key, int tableSize) {
    int hash = 0;
    for (char ch : key) {
        hash += static_cast<int>(ch);
    }
    return hash % tableSize;
}

int hashFunction2(const std::string& key, int tableSize) {
    int hash = 0;
    int base = 31;
    for (char ch : key) {
        hash = (hash * base + static_cast<int>(ch)) % tableSize;
    }
    return hash % tableSize;
}

#endif // HASHFUNCTIONS_H
