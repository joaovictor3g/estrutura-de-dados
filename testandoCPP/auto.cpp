#include <iostream>

int main() {
    int fibonacci[]{0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89};

    for(auto n : fibonacci)
        std::cout << n << " ";
    std::cout <<"\n";

    return 0;
}