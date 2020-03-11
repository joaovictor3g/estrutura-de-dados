#include <iostream>

using namespace std;

void lerMatriz(int **mat, int nl, int nc) {
    for(int i = 0; i < nl; i++) {
        for(int j = 0; j < nc; j++)     
            cin >> mat[i][j];
    }
}

int verificarSeExiste(int **mat, int nl, int nc, int elemento) {
    for(int i = 0; i < nl; i++) {
        for(int j = 0; j < nc; j++) {
            if(elemento == mat[i][j])   return 1;
        }
    }
    return 0;
}

int main() {
    int nl = 0, nc = 0;
    cout << "Digite o número de linhas e colunas: " << endl;
    cin >> nl >> nc;

    int **matriz = new int*[nl];
    for(int i = 0; i < nl; i++)
        matriz[i] = new int[nc];

    lerMatriz(matriz, nl, nc);
    int elem = 0;
    cout << "Digite um valor a ser procurado na matriz " << endl;
    cin >> elem;
    cout << verificarSeExiste(matriz, nl, nc, elem) << endl;

    for(int i = 0; i < nl; i++)
        delete[] matriz[i];
    delete[] matriz;

    return 0;
}