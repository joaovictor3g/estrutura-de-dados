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

    // std::cout << "Removendo: " << list->popBack() << std::endl;
    // std::cout << "Removendo: " << list->popBack() << std::endl;
    // std::cout << "Removendo: " << list->popBack() << std::endl;
    // std::cout << "Removendo: " << list->popBack() << std::endl;
    // list->auxRemoveNode();
    list->remove(4);
    //list->removeAll(78);
    list->print();
    list->printReverse();

    std::cout << "Tamanho da lista: " << list->size() << "\n";
    
    delete list;

    return 0;
}