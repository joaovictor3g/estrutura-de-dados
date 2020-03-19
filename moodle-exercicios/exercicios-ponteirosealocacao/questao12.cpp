#include <iostream>

using namespace std;

struct Pessoa{
    char nome[50];
    char dt_nasc[12];
    char cpf[14];
};

Pessoa *preencher(Pessoa *pessoa) {
    cout << "Digite o nome da pessoa: " << endl;
    cin.get(pessoa->nome, 50);

    cout << "Digite a data de nascimento no formato DD/MM/YY: " << endl;
    cin.ignore();
    cin.get(pessoa->dt_nasc, 12);

    cout << "Digite o cpf da pessoa: " << endl;
    cin.ignore();
    cin.get(pessoa->cpf, 14);

    return pessoa;
}

void mostrar_pessoa(Pessoa *pessoa) {
    cout << "Nome: " << pessoa->nome << endl << "Data de nascimento: " << pessoa->dt_nasc << endl << "CPF: " << pessoa->cpf << endl;
}

int main() {
    Pessoa *pessoa = new (nothrow) Pessoa;
    
    if(pessoa == nullptr) {
        cout << "Alocação mal-sucedida" << endl;
        exit(1);
    }
    pessoa = preencher(pessoa);
    mostrar_pessoa(pessoa);

    delete[] pessoa;
    pessoa = nullptr;

    return 0;
}