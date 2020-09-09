#include <iostream>
#include "Set.h"

int main() {
    Set *set = new Set();
    set->insert(1);
    set->insert(2);
    set->insert(3);

    Set *set2 = new Set();
    set2->insert(2);
    set2->insert(3);
    set2->insert(4);
    
    Set *set4 = set->simetricDiference(set, set2);
    set4->print();

    // Set *set3 = new Set();
    // set3->insert(2);
    // set3->insert(3);
    // set3->insert(4);
    // set3->insert(5);
    // set3->insert(6);
    // set3->insert(-1);
    
    // std::cout << set->min(set2) << std::endl;
    // std::cout << set->max(set2) << std::endl;
    // set3->print();
    // if(set2->isEqual(set2, set3))
    //     std::cout << "São iguais" << std::endl;

    delete set;
    delete set2;
    // delete set3;

    return 0;
}