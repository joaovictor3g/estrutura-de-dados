#include <iostream>
#include <cstdlib>

using std::cin;
using std::cout;
using std::endl;

//variavel global pra guardar o tamanho do vetor de linhas ou colunas
int size;

//Preenchendo matriz
void preencherMatriz(int **matriz, int n) {

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++)
            cin >> matriz[i][j];
    }
}

//Função para calcular o valor maximo da matriz
void max(int **matriz, int n, int *k, int *l, int *c) {
    //declarando um valor inicial muito pequeno para que a primeira condição seja satisfeita sempre
    *k = -10000000;
    int posicaoL = 0, posicaoC = 0;

    //calculo do valor maximo.
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(*k <= matriz[i][j])  *k = matriz[i][j];
            
        }
    }
    //Usando os ponteiros l e c para guardar os indices em q k aparece mais de uma vez
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(*k == matriz[i][j]) {
                l[posicaoL] = i;
                c[posicaoC] = j;
                posicaoL++;
                posicaoC++;
            }
        }
    }
    size = posicaoL;
}   

int main() {
    int tamanho = 0, maior = 0;
    cin >> tamanho;
    //Alocando matriz e vetores dinamicamente
    int **matriz = new int*[tamanho];
    int *linha = new int[tamanho];
    int *coluna = new int[tamanho];

    //Alocando coluna da matriz
    for(int i = 0; i < tamanho; i++)
        matriz[i] = new int[tamanho];
    
    preencherMatriz(matriz, tamanho);
    max(matriz, tamanho, &maior, linha, coluna);
    cout << "O maior elemento é: " << maior << endl;

    cout << "Coluna(s) e Linha(s) que o "<< maior <<" apareceu: ";

    for(int i = 0; i < size; i++)
        cout << "["<< linha[i] << "]" << "[" << coluna[i] << "]" << " ";
    cout << endl;

    //Liberando o espaco alocado
    for(int i = 0; i < tamanho; i++)
        delete[] matriz[i];
    delete[] matriz;
    delete[] linha;
    delete[] coluna;
    matriz = nullptr;
    linha = nullptr;
    coluna = nullptr;
    
    return 0;
}