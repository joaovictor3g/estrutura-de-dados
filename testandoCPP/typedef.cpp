#include <iostream>

typedef int inteiro;

inteiro dobro(inteiro x) {
    return x * x;
}

int main() {
    inteiro num = 0;
    std::cin >> num;

    std::cout << dobro(num) << std::endl;

    return 0;
}