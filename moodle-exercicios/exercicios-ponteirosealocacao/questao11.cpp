#include <iostream>

using namespace std;

int **aloc(int m, int n) {
    int **matriz = new int*[m];
    
    if(matriz == nullptr) {
        cout << "Matriz não alocada" << endl;
        exit(1);
    }

    for(int i = 0; i < m; i++) {
        matriz[i] = new int[n];
        
        if(matriz[i] == nullptr) {
            cout << "Coluna não alocada "<< endl;
            exit(1);
        }
    }
    return matriz;
}

void liberar(int **matriz, int nl, int nc) {
    for(int i = 0; i < nl; i++)
        delete[] matriz[i];
    delete[] matriz;

    for(int i = 0; i < nl; i++)
        matriz[i] = nullptr;
    matriz = nullptr;
}

int main() {
    int m = 0, n = 0;
    cin >> m >> n;

    int **matriz = aloc(m, n);
    
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) 
            cin >> matriz[i][j];
    }

    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) 
            cout << matriz[i][j] << " ";
        cout << endl;
        
    }
    
    liberar(matriz, m, n);

    return 0;
}