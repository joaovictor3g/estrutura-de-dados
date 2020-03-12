#include <iostream>

using std::cin;
using std::cout;
using std::endl;

char *strcpy(char *destino, const char *origem) {
    //enquanto o destino na posicao e i e nem origem na posicao i alcancam o barra destino recebe origem
    for(int i = 0; (destino[i] = origem[i]) ; i++);

    
    return destino;
}

int main() {
    char destino[1000];
    char origem[1000]{"Olá mundo"};

    cout << strcpy(destino, origem) << endl;

    return 0;
}