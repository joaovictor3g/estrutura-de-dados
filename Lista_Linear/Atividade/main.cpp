#include <iostream>
#include "SeqList.h"
#define MAX 20

using namespace std;

int main() {
    SeqList list(MAX);

    int i = 1;
    while(!list.isFull())  list.add(i++);
    
    for(i = 0; i < list.size(); i++) 
        cout << list.at(i) << " ";
    cout << endl;
    cout << list.at(-1) << endl;

    cout << "Tamanho da lista: " << list.size() << endl;
    list.remove(5);
    list.remove(3);
    list.remove(10);
    list.remove(2);

    list.add(1);
    list.add(1);
    cout << "Tamanho da lista: " << list.size() << endl;

    list.replaceAt(489, 6);

    list.removeAt(4);

    if(list.insertAt(908, 3)) 
        cout << "Número 908 inserido na posição 2" << endl;

    list.removeAll(1);
    cout << "Tamanho da lista: " << list.size() << endl;

    list.remove(20);
    list.remove(19);
    list.remove(18);
    list.remove(17);
    list.remove(16);
    list.remove(15);
    list.remove(14);
    list.remove(13);
    list.remove(12);
    list.add(-1);
    list.add(-1);
    list.add(-1);
    list.add(4);
    list.add(5);
    list.add(-1);
    list.add(6);
    
    list.add(8);
    
    list.removeAll(-1);
    list.removeAll(8);
    list.removeAll(6);
    list.removeAll(4);
    list.removeAll(5);

    cout << "\nLista: " << endl;
    list.print();
    cout << endl;

    return 0;
}