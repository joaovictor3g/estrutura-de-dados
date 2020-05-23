#include <iostream>

using namespace std;

int sum(int a, int b) {
    return a+b;
}

int sub(int a, int b) {
    return a-b;
}

float divi(int a, int b) {
    return a%b;
}

int mult(int a, int b) {
    return a*b;
}

int main() {
    char op;
    int a = 0, b = 0;

    cout << "Digite o primeiro número o operador e o segundo numero " << endl;
    cin >> a >> op >>  b;

    switch(op) {
        case '+': 
            cout << sum(a, b) << endl;
            break;
        
        case '-':
            cout << sub(a, b) << endl;
            break;
        
        case '*':
            cout << mult(a, b) << endl;
            break;
        
        case '/':
            cout << divi(a, b) << endl;
            break;

        default:
            cout << "Error" << endl;

    }

    return 0;
}