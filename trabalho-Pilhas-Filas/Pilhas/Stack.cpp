#include <iostream>
#include "Stack.h"
#include <climits>
#define MAX 80

struct Stack {
    int topoA; // Variavel que guarda o topo da pilha A
    int topoB; // Variavel que guarda o topo da pilha B
    int *vec; // Vetor único para armazenar os valores
};

// Cria uma lista vazia
Stack *create() {
    Stack *stack = new Stack; // Criação de uma nova pilha
    stack->vec = new int[MAX]; // Alocação do vetor
    stack->topoA = 0; // Topo da pilha A começa em 0
    stack->topoB = MAX-1; // topo da pilha B começa em 79
    return stack; // retorno pilha alocada
}

void pushA(Stack *p, int value) {
    if(p->topoA == MAX-1) { // Verificação se a pilha está cheia
        std::cout << "Estouro da pilha" << std::endl;
        exit(1);
    }else{
        p->vec[p->topoA] = value;
        p->topoA++; // Incremento topo da pilha A
    }
}

void pushB(Stack *p, int value) {
    if(p->topoB == p->topoA) { // Verificação se o topo da pilha B é igual ao topo da pilha A.
        // Se isso acontece a pilha B está cheia 
        std::cout << "Estouro da pilha" << std::endl;
        exit(1);
    }else{
        p->vec[p->topoB] = value;
        p->topoB--; // Decremento o topo da pilha A
    }
}

int popA(Stack *p) {
    if(p->topoA == 0) {
        std::cout << "Pilha vazia" << std::endl;
        return 0;
    }
    int aux = p->vec[p->topoA-1]; // Guardo o valor contido no topo
    p->topoA--; // Decremento o topo
    return aux; // Retorno valor que contém  topo
}

int popB(Stack *p) {
    if(p->topoB == MAX-1) {
        std::cout << "Pilha vazia" << std::endl;
        return 0;
    }
    int aux = p->vec[p->topoB+1];
    p->topoB++;
    return aux;
}


int topA(Stack *p) {
    if(p->topoA == 0) {
        std::cout << "Pilha está vazia" << std::endl;
        return INT_MIN;
    }
    return p->vec[p->topoA-1];
}

int topB(Stack *p) {
    if(p->topoA == MAX-1) {
        std::cout << "Pilha está vazia" << std::endl;
        return INT_MIN;
    }
    return p->vec[p->topoB+1];
}

void print(Stack *p) {
    if(p->topoA == 0) {
        std::cout << "Pilha está vazia" << std::endl;
        exit(1);
    }
    for(int i = p->topoA-1; i >= 0 ; i--) 
        std::cout << p->vec[i] << " ";
    
    if(p->topoB == MAX-1) {
        std::cout << "Pilha está vazia" << std::endl;
        exit(1);
    }
    
    for(int i = MAX-1; i >= p->topoB+1; i--) 
        std::cout << p->vec[i] << " ";

    std::cout << std::endl;
}
