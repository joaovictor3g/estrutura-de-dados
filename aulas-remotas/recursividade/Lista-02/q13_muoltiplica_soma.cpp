// . A multiplica¸c˜ao de dois n´umeros inteiros pode ser feita atrav´es de somas sucessivas.
// Implemente um algoritmo recursivo multRec(n1, n2) que calcule a multiplica¸c˜ao de
// dois inteiros

#include <iostream>

using namespace std;

int multRec(int number1, int number2) {
    if(number1==0 || number2==0)
        return 0;
    return number1+multRec(number1, number2-1);
}

int main() {
    int number1 = 0, number2 = 0;
    cin >> number1 >> number2;

    cout << multRec(number1, number2) << endl;

    return 0;
}