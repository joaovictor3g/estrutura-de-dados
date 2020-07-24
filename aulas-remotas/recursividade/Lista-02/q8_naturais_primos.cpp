// Fa¸ca uma fun¸c˜ao recursiva que receba um n´umero inteiro positivo n e imprima todos
// os n´umeros primos de 0 at´e n em ordem decrescente.

#include <iostream>

using namespace std;

bool verifica_se_primo(int);

void naturais_primos(int number) {
    if(number == 0) {
        cout << number << " ";
        return;
    }

    if(verifica_se_primo(number))
        cout << number << " ";
    naturais_primos(number-1);
}

bool verifica_se_primo(int value) {
    if(value == 1)  
        return false;

    int  cont = 0;
    for(int i = 2; i < value; i++) {
        if(value % i == 0)
            cont++;
    }

    if(cont == 0)
        return true;
    return false;
}

int main() {
    int number = 0;
    cin >> number;

    naturais_primos(number);

    return 0;
}