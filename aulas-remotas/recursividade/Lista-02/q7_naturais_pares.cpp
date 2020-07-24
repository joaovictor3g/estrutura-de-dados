// . Fa¸ca uma fun¸c˜ao recursiva que receba um n´umero inteiro positivo n e imprima todos
// os n´umeros pares de 0 at´e n em ordem decrescente

#include <iostream>

using namespace std;

void naturais_pares(int number) {
    if(number == 0) {
        cout << number;
        return; 
    }
    if(number % 2 == 0) 
        cout << number << " ";
    naturais_pares(number-1);
}

int main() {
    int number = 0;
    cin >> number;

    naturais_pares(number);

    return 0;
}