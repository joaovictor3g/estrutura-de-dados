//  A fun¸c˜ao fatorial duplo ´e definida como o produto de todos os n´umeros naturais de 1
// at´e algum n´umero natural ´ımpar n. Assim, o fatorial duplo de 5 ´e: 5!! = 1∗3∗5 = 15.
// Fa¸ca uma fun¸c˜ao que receba um n´umero inteiro positivo ´ımpar n e retorne o fatorial
// duplo desse n´umero.

#include <iostream>

using namespace std;

int fat_duplo(int number) {
    if(number == 1)
        return 1;
    if(number % 2 == 0) 
        return fat_duplo(number-1);
    return number * fat_duplo(number-2);
}

int main() {
    int number = 0;
    cin >> number;

    cout << fat_duplo(number) << endl;

    return 0;
}