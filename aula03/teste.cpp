#include <iostream>

int main() {
    int x, y, *p = nullptr;
    y = 0;
    p = &y;
    //std::cout << p << std::endl;
    x = *p;
    x = 4;
    (*p)++;
    --x;
    (*p) += x;

    char *a{"abacate"};
    std::cout << *a << std::endl;

    std::cout << *p << std::endl;

    return 0;
    
}