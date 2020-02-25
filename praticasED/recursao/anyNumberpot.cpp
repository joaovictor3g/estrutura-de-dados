#include <iostream>

using namespace std;

int AnyNumberElevate(int base, int potencia) {
    if(potencia == 0) return 1;

    return base * AnyNumberElevate(base, potencia - 1);    

}

int main() {
    int base = 0, potencia = 0;
    cin >> base >> potencia;

    cout << AnyNumberElevate(base, potencia) << endl;


    return 0;
}