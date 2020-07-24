// Escreva uma fun¸c˜ao recursiva que calcule a soma dos d´ıgitos de um n´umero inteiro.
// Por exemplo, se a entrada for 357, a sa´ıda dever´a ser 3+5+7 = 15.

#include <iostream>

using namespace std;

int sum_algarisms(int number) {
    if(number < 10) 
        return number;
    return number%10 + sum_algarisms(number/10);
}

int main() {
    int number = 0; 
    cin >> number;

    cout << sum_algarisms(number) << endl;

    return 0;
}