#include <iostream>
#include "List.h"

int main() {
    List *list = new List();
    list->pushBack(1);
    list->pushBack(2);
    list->pushBack(3);
    list->pushBack(4);
    list->pushBack(78);
    list->pushBack(78);
    list->pushBack(78);
    list->pushBack(78);
    list->pushBack(90);

    // int vetor[4]{987, 87, 767, 75};
    // list->copyArray(vetor, 4);

    // list->insertAfter(6, 1);
    std::cout << list->removeNodeAt(3) << std::endl;
    std::cout << list->removeNodeAt(1) << std::endl;
    list->print();
    list->printReverse();

    List *newList = new List();
    // newList->pushBack(10);
    // newList->pushBack(11);
    // newList->pushBack(12);
    // newList->pushBack(13);
    // newList->pushBack(14);
    // list->concat(newList);

    // if(list->equal(newList))
    //     std::cout << "Listas iguais" << std::endl;
    // else std::cout << "Listas diferentes" << std::endl;

    // list->print();
    // list->printReverse();
    // std::cout << "Tamanho da lista: " << list->size() << "\n";

    List *list2 = new List();
    // list2 = list->copy();
    // list2->print();
    // std::cout << std::endl;
    // std::cout << std::endl;
    // std::cout << std::endl;
    // std::cout << "Removendo: " << list->popBack() << std::endl;
    // std::cout << "Removendo: " << list->popBack() << std::endl;
    // std::cout << "Removendo: " << list->popBack() << std::endl;
    // std::cout << "Removendo: " << list->popBack() << std::endl;
    // list->auxRemoveNode();
    // list->remove(4);
    //list->removeAll(78);
    //

    // List *list3 = new List();
    // list3->pushBack(1);
    // list3->pushBack(2);
    // List *list4 = new List();
    // list4->pushBack(3);
    // list4->pushBack(4);

    // list3->mergeLists(list4);
    // list3->print();

    delete list;
    delete newList;
    delete list2;

    return 0;
}