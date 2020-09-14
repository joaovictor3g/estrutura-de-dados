#include <iostream>
#include "Stack.h"

int main() {
    Stack *stack = create();
    pushA(stack, 1);
    pushA(stack, 2);
    pushA(stack, 3);
    pushA(stack, 4);
    std::cout << topA(stack) << std::endl;

    pushB(stack, 8);
    pushB(stack, 19);
    std::cout << topB(stack) << std::endl;
    print(stack);

    delete stack;
    return 0;
}