#include <iostream>

using namespace std;

int **alocMatriz(int n) {
    int **mat = new (nothrow) int*[n];
    
    if(mat != nullptr) {
        for(int i = 0; i < n; i++){
            mat[i] = new ( nothrow ) int[n];
            if(mat[i] == nullptr) {
                cout << "alocaçao falhou";
                exit(1);
            }
        }
    }else {
        cout << "ALocação falhou";
        exit(1);
    }
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) { 
            mat[i][j] = 0;
            if(i == j)
                mat[i][j] = 1;
        }
    
    }
    return mat;
}

int main() {
    int n = 0;
    cin >> n;
    int **matriz = alocMatriz(n);

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++)
            cout << matriz[i][j] << " ";
        cout << endl;
    }


    for(int i = 0; i < n; i++)
        delete[] matriz[i];
    delete[] matriz;
    return 0;
}