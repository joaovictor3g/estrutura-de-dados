#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

void imprimir(char **mat, int linha, int size) {
    for(int i = 0; i < size; i++) {
        cout << mat[linha-1][i];
    }      
    cout << endl;
}

void ordenar(char **mat, int linha) {
    bool ordenado = false;
    
    while(!ordenado) {
        ordenado = false;
        for(int i = 0; i < linha - 1; i++) {
            if(strcmp(mat[i], mat[i+1]) < 0) {
                ordenado = true;
                char *aux = mat[i];
                mat[i] = mat[i+1];
                mat[i+1] = aux;
            }
        }
    }
}

void preencher(char **matriz, int qtd_palavras) {
    int palavra = 0;
    cin >> palavra; 
    
    if(qtd_palavras == 0) {
        //ordenar(matriz, qtd_palavras);
        return;

    }

    matriz[qtd_palavras-1] = new (nothrow) char[palavra];

    if(matriz[qtd_palavras-1] == nullptr) {
        cout << "Matriz não alocada" << endl;
        exit(1);
    }

    cin.ignore();
    for(int i = 0; i < palavra; i++)
        cin.get(matriz[qtd_palavras-1][i]);
        
    preencher(matriz, qtd_palavras-1);
    imprimir(matriz, qtd_palavras, palavra);
}

void liberar(char **mat, int linha) {
    for(int i = 0; i < linha; i++)
        delete[] mat[i];
    delete[] mat;
}

int main() {
    int qtd_palavras = 0;
    cin >> qtd_palavras; 

    char **matriz = new (nothrow) char*[qtd_palavras];
    
    if(matriz == nullptr) { 
        cout << "Matriz não alocada" << endl;
        exit(1);
    }
    preencher(matriz, qtd_palavras);
    liberar(matriz, qtd_palavras);

    return 0;
}