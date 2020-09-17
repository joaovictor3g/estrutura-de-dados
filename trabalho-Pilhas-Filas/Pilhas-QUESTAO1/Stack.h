#ifndef STACK_H
#define STACK_H

struct Stack;

// Cria uma Pilha vazia
Stack *create();
// Inseree um elemento na pilha: Empilhar na pilha A
void pushA(Stack *p, int value);
// Inseree um elemento na pilha: Empilhar na pilha B
void pushB(Stack *p, int value);
// Remove um elemento da pilha e retorna seu valor
int popA(Stack *p);
// Remove um elemento da pilha e retorna seu valor
int popB(Stack *p);
// Retorna valor no topo da pilha
int topA(Stack *p);
// Retorna valor no topo da pilha
int topB(Stack *p);
// Imprime os elementos da pilha
void print(Stack *p);

#endif