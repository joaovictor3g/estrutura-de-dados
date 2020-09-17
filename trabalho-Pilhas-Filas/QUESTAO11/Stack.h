#ifndef STACK_H
#define STACK_H

struct Stack;

// Cria uma pilha vazia
Stack *create();
// Adiciona elemento key na ultima posição
void push(Stack *st, int key);
// Remove o último e retorna seu valor
int pop(Stack *st);
//
bool empty(Stack *st);
//
void invert(Stack *st);
// Imprime os elementos
void print();

#endif 