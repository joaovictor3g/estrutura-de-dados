#include <iostream>

using namespace std;

struct Stack {
    string stack;
    string invertStack;
    int topo;
};

Stack *create() {
    Stack *st = new Stack;
    st->topo = 0;
    
    return st;
}

void push(Stack *st, char letter) {
    st->stack[st->topo] = letter;
    st->topo++;
}

// AMU MEGASNEM ATERCES\0

void print(Stack *st) {
    int aux = 0;  
    int counter = 0;  // Contador que verifica se só existe uma palavras
    // Percorre toda a pilha e inverte mantendo a ordem das palavras, menos a última
    
    for(int i = 0; st->stack[i] != '\0'; i++) {
        if(st->stack[i] == ' ') { // Vejo se o caractere na posição correspondente é espaço
            int aux2 = i;
            while(aux <= i-1) {
                cout << st->stack[i-1];
                i--;
            }
            cout << " ";
            i = aux2; // i recebe o valor anterior
            aux = i; // auxiliar recebe o valor de i
        }
        counter++;
    }
    if(counter == st->topo) { // Se o topo for igual ao contador quer dizer q só existe uma palavra na pilha
        for(int i = st->topo-1; i >= 0; i--)
            cout << st->stack[i];
        cout << endl;
    
    }else{ // Se não quer dizer que existe uma última palavra para ser invertida
        int index = st->topo - 1;
        while(st->stack[index] != ' ') {
            cout << st->stack[index];
            index--;
        }
    }
}

int main() {
    string phrase;
    getline(cin, phrase);

    Stack *stack = create();
    for(int i = 0; i < phrase.size(); i++) {
        push(stack, phrase[i]);
    }
    print(stack);

    return 0;
}