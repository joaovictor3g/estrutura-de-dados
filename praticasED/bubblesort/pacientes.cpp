#include <iostream>
#define TAM 2

using namespace std;

struct pacientes{
    string nome[TAM];
    int idade[TAM];

};
typedef struct pacientes pac;

void bubbleSort(int *idade, string *nome, int tamanho){
    int ordenado = 0;
   
    while(ordenado == 0){
        ordenado = 1;
        for(int i = 0; i < tamanho - 1; i++){
            if(idade[i] > idade[i+1]){
                ordenado = 0;
                int aux1 = idade[i];
                string aux2 = nome[i];
                idade[i] = idade[i+1];
                nome[i] = nome[i+1];
                idade[i+1] = aux1;
                nome[i+1] = aux2;
            }
        }
    }
    for(int i = 0; i < tamanho; i++) 
        cout << nome[i] << " " << idade[i] << endl;
}

int main() {
    pac paciente1;

    for(int i = 0; i < TAM; i++)     cin >> paciente1.nome[i] >> paciente1.idade[i];
    
    bubbleSort(paciente1.idade, paciente1.nome, TAM);

    return 0;
}