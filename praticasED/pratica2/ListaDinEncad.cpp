#include <iostream>
#include <stdlib.h>
#include "ListaDinEncad.hpp"

using namespace std;

struct elemento {
    aluno dados;
    elemento *prox;
};
typedef struct elemento Elem;

//Lista dinâmica encadeada

Lista* cria_lista(){
    Lista* li = (Lista*) malloc (sizeof(Lista));
    if(li != NULL)
        *li = NULL;
    return li;
}
void libera_lista(Lista* li){
    if(li != NULL){
        Elem* no;
        while((*li) != NULL){
            no = *li;
            *li = (*li)->prox;
            free(no);
        }
        free(li);
        cout << "Deu certo" << endl;
    }
}

