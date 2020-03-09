#include <iostream>

using namespace std;

int main() {
    int qtd = 0;
    cin >> qtd;
    int tamanho = 0;
    char **nome = new char*[qtd];
    char **aux = new char*[qtd];
    
    for(int i = 0; i < qtd; i++) {
        cin >> tamanho;
        for(int j = 0; j < tamanho; j++) {
            nome[j] = new char[tamanho];
            cin >> nome[i][j];
            
            aux[j] = new char[tamanho];
            aux[i][j] = nome[i][j];
            delete[] nome[i];

        }
        delete[] nome;
        
    }

    for(int i = 0; i < qtd; i++) 
        for(int j = 0; j < qtd; j++)
            cout << aux[i][j];
    
    for(int i = 0; i < qtd; i++) 
        delete[] aux;
    delete[] aux;


    return 0;
}