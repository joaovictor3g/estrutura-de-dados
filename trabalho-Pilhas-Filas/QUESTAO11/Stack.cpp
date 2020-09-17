#include <iostream>
#include "Stack.h"
#define MAX 100

struct Stack {
    int topo;
    int key;
    int *vec;
};

Stack *create() {
    Stack *stack = new Stack;
    stack->topo = 0;
    stack->vec = new int[MAX];

    return stack;
}

void push(Stack *st, int key) {
    if(st->topo < MAX) {
        st->vec[st->topo] = key;
        st->topo++;
    }
}

int pop(Stack *st) {
    if(empty(st)) 
        return 0;
    
    Stack *stack = new Stack;
    stack->vec = new int[MAX];
    int topo = st->topo-1;

    for(int i = 0; i < st->topo; i++) {
        stack->vec[i] = st->vec[topo];
        stack->topo = i;
        topo--;
    }
    int key = stack->vec[stack->topo];
    stack->topo--;
    return key;

}

bool empty(Stack *st) {
    return st->topo == 0;
}

