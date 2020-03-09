#include <iostream> // std::cout, std::cin, std::fixed
#include <iomanip> // std::setprecision

struct aluno {
   float nota[3];
   float media;
};

// Recebe um aluno passado por referência, e preenche o campo 'media' com a
// média das 3 notas do aluno.
void calcula_media(aluno *a, int n) {
    int mediaA = 0;
    for(int j = 0; j < n; j++) { 
        for(int i = 0; i < 3; i++) { 
            mediaA += a[j].nota[i];         
            
            if(i == 2) 
                a[j].media = mediaA / 3;
        }
    }
}

// Recebe vetor de alunos ('turma') e número de alunos ('n'), e chama a função
// 'calcula_media' (da questão anterior) para cada aluno do vetor.
// Ou seja, preenche o campo 'media' de cada aluno com a média das 3 notas do aluno.
void calcula_media_turma(aluno turma[], int n) {    
    calcula_media(turma, n);

}

int main() {
    int n, i, j;
    
    std::cin >> n;
    aluno turma[n];
    
    for (j = 0; j < n; j++)
       for (i = 0; i < 3; i++)
          std::cin >> turma[j].nota[i];
    
    // Chame a função 'calcula_media_turma' passando o vetor de alunos 'turma'.
    calcula_media(turma, n);
    
    for (j = 0; j < n; j++) {
       std::cout << std::fixed;
       std::cout << std::setprecision(1) << turma[j].media << " ";
    }
    std::cout << std::endl;
    
    return 0;
}
