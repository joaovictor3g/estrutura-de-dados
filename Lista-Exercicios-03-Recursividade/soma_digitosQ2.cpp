#include <iostream>

using namespace std;

int soma_digitos(int num) {
    if(num < 10) 
        return num;
    return (num % 10) + soma_digitos(num/10);
}

/*
    soma_digi(357) = 7 + soma_digi(35) = 7+5+3
    soma_digi(35) = 5 + soma_digi(3) = 5+3
    soma_dig(3) = 3;
*/

int main() {
    int num = 0;
    cin >> num;
    cout << soma_digitos(num) << endl;

}