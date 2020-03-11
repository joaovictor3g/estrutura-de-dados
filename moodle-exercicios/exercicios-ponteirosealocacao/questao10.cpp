#include <iostream>

using namespace std;

int **multiplicaMatriz(int **matA, int nl1, int nc1, int **matB, int nl2, int nc2) {
    int **matC = nullptr;
    if(nc1 == nl2) {
        matC = new int*[max(nl1, nl2)];
        for(int i = 0; i < max(nl1, nl2); i++)
            matC[i] = new int[max(nc1, nc2)];


        for(int i = 0; i < max(nl1, nl2); i++) {
            for(int j = 0; j < max(nc1, nc2); i++) {
                matC[i][j] = matA[i][j] * matB[j][i];
            }
        }    
    }

    return matC;
}

int main() {
    int nl1 = 0, nc1 = 0, nl2 = 0, nc2 = 0;
    cin >> nl1 >> nc1;
    int **matA = new ( nothrow ) int*[nl1];
    for(int i = 0; i < nl1; i++)
        matA[i] = new ( nothrow ) int[nc1];
    
    cin >> nl2 >> nc2;
    int **matB = new ( nothrow ) int*[nl1];
    for(int i = 0; i < nl2; i++)
        matB[i] = new (nothrow) int[nc2];

    for(int i = 0; i < nl1; i++) {
        for(int j = 0; j < nc1; j++)
            cin >> matA[i][j];
    }

    for(int i = 0; i < nl2; i++) {
        for(int j = 0; j < nc2; j++)
            cin >> matB[i][j];
    }

    for(int i = 0; i < max(nl1, nl2); i++) {
        for(int j = 0; j < max(nc1, nc2); i++) {
            cout << **multiplicaMatriz(matA, nl1, nc1, matB, nl2, nc2) << " ";
        }
        cout << endl;
    }

    for(int i = 0; i < nl1; i++)
        delete[] matA[i];
    delete[] matA;

    for(int i = 0; i < nl2; i++)
        delete[] matB[i];
    delete[] matB;


    
    return 0;
}