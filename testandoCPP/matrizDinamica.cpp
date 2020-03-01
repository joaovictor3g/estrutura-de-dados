#include <iostream>

void ordenarLinhaOuColunaCrescenteEDecrescente(int **matriz, int linhas, int colunas) {
    bool ordenado = false;
    int menor = 10000;
    while(!ordenado) {
        ordenado = true;
        for(int i = 0; i < linhas-1; i++) {
            for(int j = 0; j < colunas; j++) {
                if(matriz[i][j] > matriz[i+1][j]){
                    ordenado = false;
                    int aux = matriz[i][j];
                    matriz[i][j] = matriz[i+1][j];
                    matriz[i+1][j] = aux;
                }
            }
        }
    }
    for(int i = 0; i < linhas; i++) {
        for(int j = 0; j < colunas; j++) {
            std::cout << matriz[i][j] << " ";
        }
        std::cout << "\n";
    }
    std::cout << "\n";
    for(int i = linhas - 1; i >= 0; i--) {
        for(int j = colunas - 1; j >= 0; j--) {
            std::cout << matriz[i][j] << " ";
        }
        std::cout << "\n";
    }
}

int main() {
    int linhas = 0, colunas = 0;
    std::cin >> linhas >> colunas;

    int **matriz = new int*[linhas];
    for(int i = 0; i < linhas; i++) 
        matriz[i] = new int[colunas];
    
    for(int i = 0; i < linhas; i++) {
        for(int j = 0; j < colunas; j++) 
            std::cin >> matriz[i][j];
       
    }
    std::cout << "\n"; 
    for(int i = 0; i < linhas; i++) {
        for(int j = 0; j < colunas; j++) 
            std::cout << matriz[i][j] << " ";
        std::cout << "\n";
       
    }
    std::cout<<"\n";

    ordenarLinhaOuColunaCrescenteEDecrescente(matriz, linhas, colunas);

    for(int i = 0; i < linhas; i++)
        delete[] matriz[i];
    delete[] matriz;

    return 0;
}