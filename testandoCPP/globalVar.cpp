#include <iostream>

using std::cout;
using std::endl;

int number = 7; // variável global chamada number

int main() {
    double number = 10.5; // variável local chamada number
    // exibe valores de variáveis locais e globais
    cout << "Local double value of number = " << number << "\nGlobal int value of number = " << ::number << endl;
return 0; // indica terminação bem-sucedida
} // fim de main