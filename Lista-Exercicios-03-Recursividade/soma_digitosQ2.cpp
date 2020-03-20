#include <iostream>

using namespace std;

int soma_digitos(int num) {
    if(num < 10) 
        return num;
    return (num % 10) + soma_digitos(num/10);

}

int main() {
    int num = 0;
    cin >> num;
    cout << soma_digitos(num) << endl;

}