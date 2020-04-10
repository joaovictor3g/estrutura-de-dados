#include <iostream>
#include <queue>

using namespace std;

int main() {
    int qtd = 0;
    queue<int> comprar_pao;

    cout << "Digite a quantidade de pessoas na fila" << endl;
    cin >> qtd;

    for(int i = 0; i < qtd; i++) 
        comprar_pao.push(i);

    cout << "Tamanho da fila: "<< comprar_pao.size() << endl; 
    
    //cout << "Elemento de trás: "<< comprar_pao.back() << endl;

    int i = comprar_pao.size();
    int j = 0;
    while(i--) {
        cout << "Elemento "<< j << ": " << comprar_pao.front() << endl;
        comprar_pao.pop();
        j++;
    }

    return 0;
}