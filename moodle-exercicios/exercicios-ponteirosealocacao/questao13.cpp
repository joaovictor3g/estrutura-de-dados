#include <iostream>

using namespace std;

struct Registro{
    int matricula;
    char sobrenome[20];
    int ano_nasc;
};

Registro *preencher(Registro *registro, int qtd_alunos) {
    
    for(int i = 0; i < qtd_alunos; i++) {
        cin >> registro[i].matricula;
        cin.ignore();
        cin.get(registro[i].sobrenome, 20);
        cin >> registro[i].ano_nasc;
    }
    return registro;
}

void mostrar(Registro *registro, int qtd_alunos) {
    for(int i = 0; i < qtd_alunos; i++) {
        cout << "\nAluno " << i + 1 << ": " << endl << "Matrícula: " << registro[i].matricula << endl;
        cout << "Sobrenome: " << registro[i].sobrenome << endl;
        cout << "Ano de nascimento: " << registro[i].ano_nasc << endl;
    }
}

bool alterar(Registro *registro, int matricula, int qtd_alunos) {
    
    for(int i = 0; i < qtd_alunos; i++) {
        if(registro[i].matricula == matricula) {
            registro[i].ano_nasc = 1100;
            return true;
        }
    }
    return false;
}

int main() {
    int qtd_alunos = 0;
    cin >> qtd_alunos;

    Registro *registro = new (nothrow) Registro[qtd_alunos];

    if(registro == nullptr) {
        cout << "Alocação mal-sucedida" << endl;
        exit(1);
    }

    registro = preencher(registro, qtd_alunos);
    mostrar(registro, qtd_alunos);
    
    if(alterar(registro, 1, qtd_alunos)) 
        mostrar(registro, qtd_alunos);
    else
        cout << "Aluno inexistente" << endl; 

    delete[] registro;

    return 0;
}