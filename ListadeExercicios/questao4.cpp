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
    *k = matriz[0][0];
    int posicaoL = 0, posicaoC = 0;
    //calculo do valor maximo e usando os ponteiros l e c para guardar os indices em q k aparece mais de uma vez.
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(*k <= matriz[i][j])
                *k = matriz[i][j];
        
        }
    }

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

    //Guardando a quantidade de vezes q o maior elemento aparece
    size = posicaoC;
}   

int main() {
    int tamanho = 0, maior = 0;
    cin >> tamanho;
    //Alocando matriz e vetores dinamicamente
    int **matriz = new int*[tamanho];
    //Criando dois vetores alocados dinamicamente afim de guardar as posicoes de linha
    //e coluna do maior elemento da matriz.

    int *vetor_posicao_linha = new int[tamanho*tamanho];
    int *vetor_posicao_coluna =  new int[tamanho*tamanho]; 

    //Alocando coluna da matriz
    for(int i = 0; i < tamanho; i++)
        matriz[i] = new int[tamanho];
    
    preencherMatriz(matriz, tamanho);
    max(matriz, tamanho, &maior, vetor_posicao_linha, vetor_posicao_coluna);
    cout << "O maior elemento é: " << maior << endl;

    cout << "Coluna(s) e Linha(s) que o "<< maior <<" apareceu: ";

    for(int i = 0; i < size; i++)
        cout << "["<< vetor_posicao_linha[i] << "]" << "[" << vetor_posicao_coluna[i] << "]" << " ";
    cout << endl;

    //Liberando o espaco alocado
    delete[] vetor_posicao_coluna;
    delete[] vetor_posicao_linha;
    for(int i = 0; i < tamanho; i++)
        delete[] matriz[i];
    delete[] matriz;
    
    return 0;
}
/*
Testes
1
----------->
3
1 2 3 
3 2 1
9 0 8
<-----------
O maior elemento é: 9
Coluna(s) e Linha(s) que o 9 apareceu: [2][0] 


Teste 2
------------>
5
9 9 9 9 9
9 9 9 9 9
9 9 9 9 9 
9 9 9 9 9
9 9 9 9 9
<-------------
O maior elemento é: 9
Coluna(s) e Linha(s) que o 9 apareceu: [0][0] [0][1] [0][2] [0][3] [0][4] [1][0] [1][1] [1][2] [1][3] [1][4] [2][0] [2][1] [2][2] [2][3] [2][4] 
[3][0] [3][1] [3][2] [3][3] [3][4] [4][0] [4][1] [4][2] [4][3] [4][4] 
*/