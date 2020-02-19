#include <iostream>

using namespace std;

int main(){
    int vet[10], ordenado = 0;

    for(int i = 0; i < 10; i++) cin >> vet[i];

    //Bubble Sort
    while(ordenado == 0){
        ordenado = 1;
        for(int i = 0; i < 9; i++){
            if(vet[i] > vet[i+1]){
                ordenado = 0;
                int temp = vet[i];
                vet[i] = vet[i+1];
                vet[i+1] = temp;
            }
        }
    }
    for(int i = 0; i < 10; i++)     cout << vet[i] << " ";
    cout << endl;
    for(int i = 9; i >= 0; i--)     cout << vet[i] << " ";

    return 0;
}