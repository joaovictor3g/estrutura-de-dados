#include <iostream>
#include "List.h"

int main() {
    List *list = new List();
    list->pushBack(1);
    list->pushBack(2);
    list->pushBack(3);

    // std::cout << "Removendo: " << list->popBack() << std::endl;
    // std::cout << "Removendo: " << list->popBack() << std::endl;
    // std::cout << "Removendo: " << list->popBack() << std::endl;
    // std::cout << "Removendo: " << list->popBack() << std::endl;
    list->auxRemoveNode();
    list->print();


    delete list;

    return 0;
}