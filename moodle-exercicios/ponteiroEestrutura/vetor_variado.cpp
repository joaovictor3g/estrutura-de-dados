#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

void imprimir(char *array, int tamanho) {
    for(int i = 0; i < tamanho; i++)
        cout << array[i];
    cout << endl;

}

void preencher(int qtd_palavras) {
    if(qtd_palavras == 0)
        return;

    int palavra = 0;
    cin >> palavra;
    
    char vetor[palavra];
    cin.ignore();
    cin.get(vetor, palavra+1);

    preencher(qtd_palavras-1);    
    imprimir(vetor, palavra);            

}

int main() {
    int qtd_palavras = 0;
    cin >> qtd_palavras; 

    preencher(qtd_palavras);

    return 0;
}