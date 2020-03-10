#include <iostream>

using namespace std;

struct Cadastro {
    string nome;
    int idade;
    string endereco;

};

Cadastro *aloc(int n) {
    Cadastro *array = new Cadastro[n];

    if(array ==  nullptr) {
        cout << "Vetor não alocado" << endl;
        exit(1);
    }
    for(int i = 0; i < n; i++) {
        cin >> array[i].nome;
        cin >> array[i].idade;
        cin >> array[i].endereco;
    }
    return array;
}

int main() {
    int n = 0;
    cin >> n;
    Cadastro *cad = aloc(n);

    if(cad == nullptr) {
        cout << "Error";
        exit(1);
    }
    for(int i = 0; i < n; i++) {
        cout << cad[i].nome << " ";
        cout << cad[i].idade << " ";
        cout << cad[i].endereco << " " << endl;
    }

    delete[] cad;

    return 0;
}