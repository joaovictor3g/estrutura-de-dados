#include <iostream>
#include "Set.h"

int main() {
    Set *set = new Set();
    set->insert(1);
    set->insert(2);
    set->insert(3);
    set->insert(7);
    set->insert(1);
    set->insert(2);
    set->insert(3);
    set->insert(7);

    Set *set2 = new Set();
    set2->insert(2);
    set2->insert(3);
    set2->insert(4);
    set2->insert(5);
    set2->insert(6);


    Set *set3 = new Set();
    set3 = set->diference(set, set2);
    // set->remove(2);
    // set->remove(3);
    
    // std::cout << set->member(1) << std::endl;
    set3->print();

    delete set;
    delete set2;
    delete set3;

    return 0;
}