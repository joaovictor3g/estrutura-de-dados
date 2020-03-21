#include <iostream>
#include <cstdlib>
#include <iomanip>

using namespace std;

struct aluno {
    int matricula;
    char nome[50];
    float media;

};

aluno le_aluno() {
    aluno a;
    cin >> a.matricula;
    cin.ignore(); // lê e descarta o caractere '\n' do buffer 
    cin.get(a.nome, 50);
    cin >> a.media;
    
    return a;
}

aluno *insere_aluno(aluno *v, int *n, aluno novo) {
    aluno *aux = new (nothrow) aluno[*n+1];
    for(int i = 0; i < *n; i++)
        aux[i] = v[i];
    
    aux[*n] = novo;
    *n = *n+1;
    delete[] v;

   return aux;   
}

aluno *remove_aluno(aluno *v, int *n, int matricula) {
    for(int i = 0; i < *n; i++) {
        if(v[i].matricula == matricula) {
            v[i] = v[*n-1];

            aluno *aux = new (nothrow) aluno[*n-1];
            for(int j = 0; j < *n-1; j++)
                aux[j] = v[j];
            delete[] v;
            return aux;
            
        }
    }
    return v;
}

int main() {
    int num_oper = 0, i, n = 0;
    cin >> num_oper;
    aluno *v = 0;
    aluno *aux = 0;

    for (i = 0; i < num_oper; i++) {
        cin.ignore(); // lê e descarta o caractere '\n' do buffer 
        char oper;
        cin >> oper;
        if (oper == 'i') {
            aluno a = le_aluno();
            v = insere_aluno(v, &n, a);
        

        } else if(oper == 'r'){
            int mat;
            cin >> mat;
            v = remove_aluno(v, &n, mat);
        
        }
    }    

    //cout << n << endl;

    for (i = 0; i < n; i++) 
        cout << v[i].matricula << "\n" << v[i].nome << "\n" << std::fixed << setprecision(1) << v[i].media << "\n";

    free(v);
   
    return 0;
}