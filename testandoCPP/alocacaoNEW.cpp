#include <iostream>
#include <cstdlib>

int main() {
    double *ptr = new ( std::nothrow ) double[1000000000];

    if(!ptr) {
        std::cout << "Error: Memory Overflow" << std::endl;
        exit(1);
    }

    delete[] ptr;
    ptr = nullptr;

    return 0;
}