#include <iostream>
#include "List.h"

int main() {
    List *list = new List();
    list->addBack(6);
    list->addBack(8);
    list->addFront(1);
    list->addFront(6);
    list->addFront(-9);


    list->removeAll(6);
    // list->print();
    std::cout << list->size() << std::endl; 

    return 0;
}