#include <iostream>

using namespace std;

void algoritmoEuclides(int dividendo, int divisor){
    int resto = 0, i = 0;

    if(divisor == 0)    cout << dividendo << endl;

    while(dividendo%divisor != 0){
        resto = dividendo%divisor;
        cout << "O resto na " << i << " iteraçaõ é: " << resto << endl; 
        dividendo = divisor;
        cout << "O dividendo na " << i << " iteraçaõ é: " << dividendo << endl;
        divisor = resto;
        cout << "O divisor na " << i << " iteraçaõ é: " << divisor << endl;
        i++;
    }   

}

int main(){
    int dividendo = 0, divisor = 0;
    cin >> dividendo >> divisor;
    algoritmoEuclides(dividendo, divisor);


    return 0;
}