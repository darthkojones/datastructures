#include <iostream>
#include "HashTable.h"
#include "hashFunctions.h"

int main() {
    HashTable table1(10, hashFunction1);
    table1.insert("Alice", "123-4567");
    table1.insert("Bob", "234-5678");
    table1.insert("Charlie", "345-6789");
    table1.insert("David", "456-7890");
    table1.insert("Eve", "567-8901");
    
    std::cout << "Table 1 (Hash Function 1):" << std::endl;
    table1.print();
    
    HashTable table2(10, hashFunction2);
    table2.insert("Alice", "123-4567");
    table2.insert("Bob", "234-5678");
    table2.insert("Charlie", "345-6789");
    table2.insert("David", "456-7890");
    table2.insert("Eve", "567-8901");
    
    std::cout << "Table 2 (Hash Function 2):" << std::endl;
    table2.print();

    std::string value;
    if (table2.search("Charlie", value)) {
        std::cout << "Found Charlie: " << value << std::endl;
    } else {
        std::cout << "Charlie not found." << std::endl;
    }

    table2.remove("Bob");
    std::cout << "Table 2 after removing Bob:" << std::endl;
    table2.print();

    table2.remove("Alice");
    std::cout << "Table 2 after removing Alice:" << std::endl;
    table2.print();

    return 0;
}
