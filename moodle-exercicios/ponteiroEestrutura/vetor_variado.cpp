#include <iostream>
#include <cstring>

using namespace std;

void imprimir(char **mat, int indice) {
    for(int i = 0; i < indice; i++)
        cout << mat[i] << endl;
    
}

void ordenar(char **mat, int indice) {
    if(indice == 1) {
        imprimir(mat, indice);
        return;
    }
    //Ordenando a matriz em ordem alfabetica
    bool ordenado = false;
    while(!ordenado) {
        ordenado = true;
        for(int i = 0; i < indice-1; i++) {
            if(strcmp(mat[i], mat[i+1]) > 0) {
                ordenado = false;
                char *aux = mat[i];
                mat[i] = mat[i+1];
                mat[i+1] = aux;
            }
        }
    }
    imprimir(mat, indice);
}

void preencher(char **matriz, int qtd_palavras, int indice) {
    int palavra = 0;
    cin >> palavra;

    //Alocando as colunas da matriz
    matriz[indice] = new (nothrow) char[palavra];

    if(matriz[indice] == nullptr) {
        cout << "Matriz não alocada" << endl;
        exit(1);
    }

    cin.ignore();
    for(int i = 0; i < palavra; i++)
        cin.get(matriz[indice][i]);

    indice++;
    if(indice == qtd_palavras)
        ordenar(matriz, indice);   
    
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
    //Chamando a funcao preencher qtd_palavras vezes.
    for(int i = 0; i < qtd_palavras; i++)
        preencher(matriz, qtd_palavras, i);
    
    liberar(matriz, qtd_palavras);

    return 0;
}