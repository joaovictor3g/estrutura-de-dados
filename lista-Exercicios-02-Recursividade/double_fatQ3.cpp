#include <iostream>

using namespace std;

int duplo_fat(int num) {
    if(num == 1 || num == 0)    return 1;

    return num * duplo_fat(num - 2);
}

int main() {
    int numero = 0;
    cin >> numero;
    cout << duplo_fat(numero) << endl;

    return 0;
}