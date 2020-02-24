#include <iostream>

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

    for(int i = 0; i < linhas; i++) {
        for(int j = 0; j < colunas; j++) 
            std::cout << matriz[i][j] << " ";
        std::cout << "\n";
       
    }

    for(int i = 0; i < 3; i++)
        delete[] matriz[i];
    delete[] matriz;

    return 0;
}