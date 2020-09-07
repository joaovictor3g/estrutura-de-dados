#include <iostream>
#include "Set.h"

int main() {
    Set *set = new Set();
    set->add(1);
    set->add(2);
    set->add(3);

    Set *set2 = new Set();
    set2->add(2);
    set2->add(3);
    set2->add(4);
    set2->add(5);
    set2->add(6);


    Set *set3 = new Set();
    set3 = set->diference(set, set2);

    set3->print();
    return 0;
}