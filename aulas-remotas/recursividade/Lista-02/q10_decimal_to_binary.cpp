// Dado um n´umero n na base decimal, escreva uma fun¸c˜ao recursiva que converte este
// n´umero para bin´ario

#include <iostream>

using namespace std;

void convert_to_binary(int number) {
    if(number < 1)
        return;
    convert_to_binary(number/2);
    cout << number%2;
}

int main() {
    int number_decimal = 0;
    cin >> number_decimal;

    convert_to_binary(number_decimal);

    return 0;
}