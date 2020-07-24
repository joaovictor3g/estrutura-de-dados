// Fa¸ca uma fun¸c˜ao recursiva que receba um n´umero inteiro positivo n e imprima todos
// os n´umeros naturais de 0 at´e n em ordem decrescente

#include <iostream>

using namespace std;

void imprimir_naturais(int number) {
    if(number == 0) {
        cout << "0";
        return; 
    }
    cout << number<< " ";
    imprimir_naturais(number-1);
}

int main() {
    int number = 0;
    cin >> number;

    imprimir_naturais(number);

    return 0;
}