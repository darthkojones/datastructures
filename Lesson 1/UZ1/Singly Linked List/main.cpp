#include <iostream>
#include "SinglyLinkedList.h"

int main() {
    // 1. Create a singly linked list
    SinglyLinkedList list;

    // 2. Print out all the elements of the list and its size
    std::cout << "Initial list:" << std::endl;
    list.print();

    // 3. Add 17 as last element then print out all the elements of the list and its size
    list.addLast(17);
    std::cout << "After adding 17 as last element:" << std::endl;
    list.print();

    // 4. Add 28 as last element then print out all the elements of the list and its size
    list.addLast(28);
    std::cout << "After adding 28 as last element:" << std::endl;
    list.print();

    // 5. Add 1 as first element then print out all the elements of the list and its size
    list.addFirst(1);
    std::cout << "After adding 1 as first element:" << std::endl;
    list.print();

    // 6. Add at position 1 the element with value -100 (NOTE: position 1 is the FIRST element!)
    list.addAt(1, -100);
    std::cout << "After adding -100 at position 1:" << std::endl;
    list.print();

    // 7. Insert element with value 100 at position 100 then print out all the elements of the list and its size
    list.addAt(100, 100);
    std::cout << "After adding 100 at position 100:" << std::endl;
    list.print();

    // 8. Add 3800 as last element then print out all the elements of the list and its size
    list.addLast(3800);
    std::cout << "After adding 3800 as last element:" << std::endl;
    list.print();

    // 9. Add at position 2 the element with value 2222 (NOTE: position 1 is the FIRST element!)
    list.addAt(2, 2222);
    std::cout << "After adding 2222 at position 2:" << std::endl;
    list.print();

    // 10. Add at position 4 the element with value 4444 (NOTE: position 1 is the FIRST element!)
    list.addAt(4, 4444);
    std::cout << "After adding 4444 at position 4:" << std::endl;
    list.print();

    // 11. Remove the first element then print out all the elements of the list and its size
    list.removeFirst();
    std::cout << "After removing the first element:" << std::endl;
    list.print();

    // 12. Remove the first element then print out all the elements of the list and its size
    list.removeFirst();
    std::cout << "After removing the first element again:" << std::endl;
    list.print();

    // 13. Remove the last element then print out all the elements of the list and its size
    list.removeLast();
    std::cout << "After removing the last element:" << std::endl;
    list.print();

    // 14. Remove the last element then print out all the elements of the list and its size
    list.removeLast();
    std::cout << "After removing the last element again:" << std::endl;
    list.print();

    // 15. Remove the element at location 2 (NOTE: position 1 is the FIRST element!)
    list.removeAt(2);
    std::cout << "After removing the element at location 2:" << std::endl;
    list.print();

    // 16. Remove the element at location 2 (NOTE: position 1 is the FIRST element!)
    list.removeAt(2);
    std::cout << "After removing the element at location 2 again:" << std::endl;
    list.print();

    // 17. Remove the element at location 3 (NOTE: position 1 is the FIRST element!)
    list.removeAt(3);
    std::cout << "After removing the element at location 3:" << std::endl;
    list.print();

    return 0;
}
