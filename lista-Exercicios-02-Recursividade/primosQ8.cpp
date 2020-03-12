#include <iostream>

using namespace std;

bool verificar_se_primo(int num) {
    for(int i = 2; i < num; i++) {
        if(num % i == 0)
            return false;
    }
    return true;
}

void mostrar_primos(int num) {
    if(num < 2) return;
    
    if(verificar_se_primo(num))
        cout << num << " ";
    mostrar_primos(num - 1);

}

int main() {
    int num = 0;
    cin >> num;
    mostrar_primos(num);

    return 0;
}