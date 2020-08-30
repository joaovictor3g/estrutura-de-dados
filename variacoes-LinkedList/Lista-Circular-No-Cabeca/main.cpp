#include <iostream>
#include "List.h"

int main() {
    List *list = new List();
    list->addBack(87);
    list->addBack(87);
    list->addBack(76);
    list->addBack(-90);

    list->addFront(45);
    list->addFront(10);

    list->remove(76);
    list->removeAll(87);
    list->print();

    return 0;
}