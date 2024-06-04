#include "HashTable.h"

HashTable::HashTable(int size, int (*hashFunc)(const std::string&, int)) : size(size), hashFunction(hashFunc) {
    table.resize(size);
}

void HashTable::insert(const std::string& key, const std::string& value) {
    int hash = hashFunction(key, size);
    table[hash].emplace_back(key, value);
}

bool HashTable::search(const std::string& key, std::string& value) const {
    int hash = hashFunction(key, size);
    for (const auto& item : table[hash]) {
        if (item.first == key) {
            value = item.second;
            return true;
        }
    }
    return false;
}

bool HashTable::remove(const std::string& key) {
    int hash = hashFunction(key, size);
    for (auto it = table[hash].begin(); it != table[hash].end(); ++it) {
        if (it->first == key) {
            table[hash].erase(it);
            return true;
        }
    }
    return false;
}

void HashTable::print() const {
    for (int i = 0; i < size; ++i) {
        std::cout << "Bucket " << i << ":";
        for (const auto& item : table[i]) {
            std::cout << " (" << item.first << ", " << item.second << ")";
        }
        std::cout << std::endl;
    }
}
