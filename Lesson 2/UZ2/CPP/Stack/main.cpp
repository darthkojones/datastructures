#include <iostream>
#include "Stack.h"

int main() {
    Stack stack;

    // 1. Create a stack (already created)

    // 2. Print out all the elements of the stack and its size
    std::cout << "Stack elements: ";
    stack.printStack();
    std::cout << "Stack size: " << stack.getSize() << std::endl;

    // 3. Add elements with values 100, 200, and 300 to the stack
    stack.push(100);
    stack.push(200);
    stack.push(300);

    // 4. Print out all the elements of the stack and its size
    std::cout << "Stack elements: ";
    stack.printStack();
    std::cout << "Stack size: " << stack.getSize() << std::endl;

    // 5. Remove all elements from the stack, and after you remove an element print out the remaining elements on the stack and its size
    stack.pop();
    std::cout << "Stack elements after pop: ";
    stack.printStack();
    std::cout << "Stack size: " << stack.getSize() << std::endl;

    stack.pop();
    std::cout << "Stack elements after pop: ";
    stack.printStack();
    std::cout << "Stack size: " << stack.getSize() << std::endl;

    stack.pop();
    std::cout << "Stack elements after pop: ";
    stack.printStack();
    std::cout << "Stack size: " << stack.getSize() << std::endl;

    // 6. Peek the current element on the stack and print it out
    std::cout << "Current element (peek): " << stack.peek() << std::endl;

    // 7. Add element with value 400 to the stack
    stack.push(400);

    // 8. Peek the current element on the stack and print it out
    std::cout << "Current element (peek): " << stack.peek() << std::endl;

    // 9. Print out all the elements of the stack and its size
    std::cout << "Stack elements: ";
    stack.printStack();
    std::cout << "Stack size: " << stack.getSize() << std::endl;

    // 10. Remove an element from the stack
    stack.pop();

    // 11. Print out all the elements of the stack and its size
    std::cout << "Stack elements: ";
    stack.printStack();
    std::cout << "Stack size: " << stack.getSize() << std::endl;

    return 0;
}
