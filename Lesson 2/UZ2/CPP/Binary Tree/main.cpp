#include <iostream>
#include "BinaryTree.h"

int main() {
    BinaryTree tree;

    // 1. Create a Binary Tree (already created)

    // 2. Print out all the elements of the tree and its size
    std::cout << "Tree elements (pre-order): ";
    tree.preOrder();
    std::cout << "Tree size: " << tree.size() << std::endl;

    // 3. Add elements 7, 5, 3, 15, 13, 17, 12, 14, 16, 19 in exactly that sequence
    tree.insert(7);
    tree.insert(5);
    tree.insert(3);
    tree.insert(15);
    tree.insert(13);
    tree.insert(17);
    tree.insert(12);
    tree.insert(14);
    tree.insert(16);
    tree.insert(19);

    // 4. Print out the elements of the tree in pre-order sequence
    std::cout << "Tree elements (pre-order): ";
    tree.preOrder();

    // 5. Remove element 7
    tree.deleteNode(7);

    // 6. Print out the elements of the tree in pre-order sequence
    std::cout << "Tree elements (pre-order): ";
    tree.preOrder();

    // 7. Remove element 17
    tree.deleteNode(17);

    // 8. Print out the elements of the tree in pre-order sequence
    std::cout << "Tree elements (pre-order): ";
    tree.preOrder();

    // 9. Remove element 15
    tree.deleteNode(15);

    // 10. Print out the elements of the tree in pre-order sequence
    std::cout << "Tree elements (pre-order): ";
    tree.preOrder();

    // 11. Print out the elements of the tree in post-order sequence
    std::cout << "Tree elements (post-order): ";
    tree.postOrder();

    // 12. Print out the elements of the tree in in-order sequence
    std::cout << "Tree elements (in-order): ";
    tree.inOrder();

    return 0;
}
