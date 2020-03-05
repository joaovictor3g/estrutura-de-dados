#include <iostream>

void moveTorre(int, char, char, char);

void moveDisco(int, char, char);

int main() {
    moveTorre(7, 'A', 'C', 'B');


    return 0;
}

void moveTorre(int n, char origem, char destino, char aux) {
    if(n == 1)
        moveDisco(n, origem, destino);
    
    else {
        moveTorre(n-1, origem, aux, destino);
        moveDisco(n, origem, destino);
        moveTorre(n-1, aux, destino, origem);
    }

}

void moveDisco(int disco, char origem, char destino) {
    std::cout << "\nMovimento: disco " << disco << " " << "de " << origem << " " << "---> " << destino << std::endl; 
}