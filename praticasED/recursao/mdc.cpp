#include <iostream>

using namespace std;

int algoritmoEuclides(int dividendo, int divisor){
    int resto = 0;

    if(divisor == 0)    cout << dividendo << endl;

    while(dividendo%divisor != 0){
        resto = dividendo%divisor;
        dividendo = divisor;
        divisor = resto;
    }   
    return divisor;
}

int minimoMultiploComum(int a, int b){
    return a * b / algoritmoEuclides(a, b); 
}

int main(){
    int dividendo = 0, divisor = 0;
    cin >> dividendo >> divisor;
    cout << "O MDC é igual a: " << algoritmoEuclides(dividendo, divisor) << endl;
    cout << "O MMC é igual a: " << minimoMultiploComum(dividendo, divisor) << endl;

    return 0;
}