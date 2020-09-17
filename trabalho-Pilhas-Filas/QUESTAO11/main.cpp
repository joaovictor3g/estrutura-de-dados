#include <iostream>
#include "Stack.h"

using namespace std;

int main() {
    Stack *stack1 = create();

    push(stack1, 1);
    push(stack1, 2);
    push(stack1, 3);
    push(stack1, 4);

    cout << pop(stack1);

    return 0;
}