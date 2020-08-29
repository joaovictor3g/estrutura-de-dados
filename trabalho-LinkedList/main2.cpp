#include <iostream>
#include "List2.h"

using namespace std;

int main() { 
    List *list = new List();

    list->add(7);
    list->add(1);
    list->add(1);
    list->add(1);
    list->add(1);
    list->add(1);
    list->add(8);
    list->add(8);
    list->add(1);
    list->add(1);
    list->add(8989);

    // list->removeAll(8);
    // list->removeAll(1);
    // list->print();
    // cout << list->removeNodeAt(6) << endl;
    // cout << list->size() << endl;
    // cout << list->removeNodeAt(6) << endl;
    // cout << list->removeNodeAt(1) << endl;
    // list->insertAfter(10, 3);
    // list->insertAfter(11, 5);
    // list->insertAfter(12, 12);
    // list->insertAfter(13, 13);
    
    // cout << list->size() << endl;
    // list->print();
    // list->print();

    List *newList = new List();
    newList->add(7);
    newList->add(1);
    newList->add(1);
    newList->add(1);
    newList->add(1);
    newList->add(1);
    newList->add(8);
    newList->add(1);

    List *listEmpty = new List(); 
    //List *listCopied = listEmpty->copy();
    
    // listCopied->print();

    List *otherList = new List();
    otherList->add(-1);
    otherList->add(1);
    otherList->add(2);
    otherList->add(3);
    otherList->add(4);
    otherList->reverse();
    otherList->print();

    // if(list->equal(newList))
    //     cout << "Listas iguais" << endl;
    // else 
    //     cout << "Listas diferentes" << endl;

    // list->concatenate(newList);
    // list->print();

    // newList->reverse();
    // newList->print();
    // newList->print();
    // int vetor[5] = {1, 2, 3, 4, 5};
    // list->copyArray(vetor, 5);
    // list->print();
    return 0;
}
