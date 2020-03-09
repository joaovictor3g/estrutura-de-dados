#include <iostream>

using namespace std;

void fillArray(int **mat, int nl, int nc) {
    for(int i = 0; i < nl; i++) {
        for(int j = 0; j < nc; j++) 
            cin >> mat[i][j];
    }
}

int maiorElemento(int **mat, int nl, int nc) {
    int maior = mat[0][0];
    for(int i = 0; i < nl; i++) {
        for(int j = 0;  j < nc; j++) {
            if(maior <= mat[i][j])
                maior = mat[i][j];
            
        }
    }
    return maior;
}

void imprimirMatriz(int **mat, int nl, int nc) {
    for(int i = 0; i < nl; i++) {
        for(int j = 0; j < nc; j++) 
            cout << mat[i][j] << " ";
        cout << endl;       
    }

}

int main() {
    int nl = 0, nc = 0;
    cin >> nl >> nc;
    int **matriz = new ( nothrow ) int*[nl];

    for(int i = 0; i < nl; i++)
        matriz[i] = new int[nc];

    if(matriz != nullptr) {
        fillArray(matriz, nl, nc);
        cout << "O maior elemento da matriz é: " <<  maiorElemento(matriz, nl, nc) << endl;
        imprimirMatriz(matriz, nl, nc);

    } else 
        cout << "Matriz não foi alocada" << endl;
    
    for(int i = 0; i < nl; i++)
        delete[] matriz[i];
    delete[] matriz;

    return 0;
}