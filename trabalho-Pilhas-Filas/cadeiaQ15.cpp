#include <iostream>
#define MAX 100

using namespace std;

struct Stack {
    char* letter;
    int topo;
};

void push(Stack *st, char letter) {
    st->letter[st->topo] = letter;
    st->topo++;
}

bool invertEqual(Stack *st) {
    Stack *novo = new Stack;
    novo->letter = new char[MAX];

    int index = st->topo-1;
    for(int i = 0; i < st->topo; i++) {
        novo->letter[i] = st->letter[index]; // Usando a nova pilha para receber os elementos invertidos
        novo->topo++; // Atualizo o topo da nova pilha
        index--;
    }
    int counter = 0;
    int position = novo->topo-1; 

    for(int i = 0; i < st->topo; i++) {
        if(novo->letter[position] == st->letter[i])    counter++;
        position--;
    }

    return (counter == st->topo);
}



int main() {
    Stack *stack = new Stack;
    stack->letter = new char[MAX];
    
    push(stack, 'A');
    push(stack, 'B');
    push(stack, 'A');
    push(stack, 'B');
    push(stack, 'B');
    push(stack, 'A');

    if(invertEqual(stack)) {
        cout << "São iguais" << endl;
    }else{
        cout << "São diferentes" << endl;
    }


    return 0;
}