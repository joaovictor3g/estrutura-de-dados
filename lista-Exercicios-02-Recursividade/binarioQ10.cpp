#include <iostream>

using namespace std;

void retornar_em_binario(int num) {
    if(num == 0) {
        cout << num;
        return;
    }
    if(num == 1) {
        cout << num;
        return;
    }
    retornar_em_binario(num/2);
    cout << num % 2;
}

int main() {
    int num = 0;
    cin >> num;

    retornar_em_binario(num);

    return 0;
}