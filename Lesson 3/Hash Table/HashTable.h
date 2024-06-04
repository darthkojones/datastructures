#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <iostream>
#include <vector>
#include <list>
#include <string>

class HashTable {
private:
    std::vector<std::list<std::pair<std::string, std::string>>> table;
    int size;
    int (*hashFunction)(const std::string&, int);

public:
    HashTable(int size, int (*hashFunc)(const std::string&, int));
    void insert(const std::string& key, const std::string& value);
    bool search(const std::string& key, std::string& value) const;
    bool remove(const std::string& key);
    void print() const;
};

#endif // HASHTABLE_H
