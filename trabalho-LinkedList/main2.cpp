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

    // list->removeAll(8);
    // cout << list->removeNodeAt(6) << endl;
    // cout << list->size() << endl;
    // cout << list->removeNodeAt(6) << endl;
    // cout << list->removeNodeAt(1) << endl;
    list->insertAfter(10, 3);
    list->insertAfter(11, 5);
    list->insertAfter(12, 12);
    list->insertAfter(13, 13);
    
    cout << list->size() << endl;
    list->print();

    return 0;
}
