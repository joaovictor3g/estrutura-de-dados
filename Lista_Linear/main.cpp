#include <iostream>
#include "SeqList.h"
#define MAX 10

using namespace std;

int main() {
    SeqList list(MAX);

    int i = 1;
    while(!list.isFull())  list.add(i++);
    
    for(i = 0; i < list.size(); i++) 
        cout << list.at(i) << " ";
    cout << endl;

    // cout << "Tamanho da lista: " << list.size() << endl;
    list.remove(5);
    list.remove(3);
    list.remove(10);
    list.remove(2);

    list.add(1);
    list.add(1);
    // cout << "Tamanho da lista: " << list.size() << endl;
    
    list.removeAll(1);

    list.replaceAt(489, 1);

    list.removeAt(4);

    cout << "\nLista com 3, 5 e 10 e todos os 1s removidos, inserindo um valor diferente na posição 1: " << endl;
    list.print();
    cout << endl;

    return 0;
}