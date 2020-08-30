#include <iostream>
#include "List.h"

int main() {
    List *list = new List();
    list->addBack(90);
    list->addBack(87);
    list->addBack(87);
    list->addBack(87);
    list->addBack(87);
    list->addBack(34);
    list->addFront(1);

    list->remove(90);
    list->removeAll(87);

    list->print();
    list->printReverse();

    return 0;
}