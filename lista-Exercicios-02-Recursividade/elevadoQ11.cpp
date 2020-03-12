#include <iostream>

using namespace std;

int elevate(int base, int potencia) {
    if(potencia == 0)
        return 1;
    return base * elevate(base, potencia-1);
}

int main() {
    int base = 0, potencia = 0;
    cin >> base >> potencia;
    cout << elevate(base, potencia);
    
    return 0;
}