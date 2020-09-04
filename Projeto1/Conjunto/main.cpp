#include <iostream>
#include "Set.h"

int main() {
    Set *set = new Set();
    set->add(1);
    set->add(2);
    set->add(3);

    set->print();

    return 0;
}