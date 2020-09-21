/*
    Nome: João Victor Dias Barroso
    Matricula: 474110
*/


#include <iostream>
#include "Set.h"

using namespace std;

void addToSet(Set *set, int key) {
    set->insert(key);
    cout << "Valor adicionado ao conjunto" << endl;
}

void unionSets(Set *set1, Set *set2) {
    set1 = set1->unionSet(set1, set2);
    cout << "Conjuntos unidos!!!"<< endl;
}

void intersectionSets(Set *set1, Set *set2) {
    set1 = set1->intersectionSet(set1, set2);
    
    if(set1->isEmptySet()) {
        cout << "Intersecção: {Ø}" << endl;
        return;
    }
    cout << "Intersecção: ";
    set1->print();
    cout << endl;
}

void print(Set *set) {
    set->print();
}

int listSize(Set *set) {
    return set->size();
}

void diferenceSet(Set *set1, Set *set2) {
    set1 = set1->diference(set1, set2);
    set1->print();
}   

void removeKey(Set *set, int key) {
    if(!set->contains(key)) {
        cout << "Valor inexistente no conjunto!!" << endl;
        return;
    }
    set->remove(key);
    cout << key << " removido com sucesso" << endl;
}

bool isMember(Set *set, int key) {
    return (set->member(key) == 1);
}

void simetricDif(Set *set1, Set *set2) {
    set1 = set1->simetricDiference(set1, set2);
    set1->print();
}

void menu(Set *set1, Set *set2) {
    int option = 0;
    cout << "1 - Adicionar ao conjunto A               2 - Adicionar ao conjunto B" << endl;
    cout << "3 - Unir os dois conjuntos(A + B)         4 - imprimir conjunto" << endl;
    cout << "5 - Interseccão dos conjuntos(A ∩ B)      6 - Diferença entre os conjuntos(A - B)" << endl;
    cout << "7 - Remover valor de um conjunto          8 - Membro" << endl;
    cout << "9 - Menor valor do conjunto               10 - Maior valor do conjunto" << endl;
    cout << "11 - Diferença simétrica(A ⊕ B)" << endl;
 
    cin >> option;
    int backToPrincipalMenu = 0;

    while(true) {
        switch(option) {
            case 1: {
                system("clear");
                int key = 0;
                cout << "Digite um valor para adicionar" << endl;
                cin >> key;

                addToSet(set1, key);
                print(set1);

                cout << "Voltar ao menu principal? 1 - Sim 0 - Não " << endl;
                cin >> backToPrincipalMenu;

                if(backToPrincipalMenu == 1)
                    menu(set1, set2);
                break;
            }

            case 2: {
                system("clear");
                int key = 0;
                cout << "Digite um valor para adicionar" << endl;
                cin >> key;

                addToSet(set2, key);
                print(set2);

                cout << "Voltar ao menu principal? 1 - Sim 0 - Não " << endl;
                cin >> backToPrincipalMenu;

                if(backToPrincipalMenu == 1)
                    menu(set1, set2);
                break;
                
            }

            case 3: {
                system("clear");
                unionSets(set1, set2);
                menu(set1, set2);
            
            }

            case 4: {
                system("clear");
                set1->print();
                cout << "Voltar ao menu principal? 1 - Sim 0 - Não " << endl;
                cin >> backToPrincipalMenu;

                if(backToPrincipalMenu == 1)
                    menu(set1, set2);
                break;


            }

            case 5: {
                system("clear");
                intersectionSets(set1, set2);
                cout << endl;

                cout << "Voltar ao menu principal? 1 - Sim 0 - Não " << endl;
                cin >> backToPrincipalMenu;

                if(backToPrincipalMenu == 1)
                    menu(set1, set2);
                break;
            }

            case 6: {
                system("clear");
                cout << "Diferença entre os conjuntos A = ";
                set1->print();
                cout << " e B = ";
                set2->print(); 
                cout << " é:" ;
                diferenceSet(set1, set2);
                
                cout << "Voltar ao menu principal? 1 - Sim 0 - Não " << endl;
                cin >> backToPrincipalMenu;

                if(backToPrincipalMenu == 1)
                    menu(set1, set2);
                break;
            }

            case 7: {
                system("clear");
                int choice = 0;
                int key = 0;
                cout << "De qual conjunto remover? 1 - Conjunto A   2 - Conjunto B" << endl;
                cin >> choice;

                if(choice == 1) {
                    cout << "Conjunto A = ";
                    set1->print();
                    cout << "Valor a ser removido?" << endl;
                    cin >> key;    
                    removeKey(set1, key);
                
                } else if(choice == 2)  { 
                    cout << "Conjunto B = ";
                    set2->print();
                    cout << "Valor a ser removido?" << endl;
                    cin >> key;
                    removeKey(set2, key);
                
                }
                else    cout << "Valor invalido" << endl;

                cout << "Voltar ao menu principal? 1 - Sim 0 - Não " << endl;
                cin >> backToPrincipalMenu;

                if(backToPrincipalMenu == 1)
                    menu(set1, set2);
                break;
            }

            case 8: {
                system("clear");
                int key = 0;
                cout << "Verificar se um valor pertence a pelo menos um conjunto, digite-o" << endl;
                cin >> key;
                if(isMember(set1, key) || isMember(set2, key)) 
                    cout << "Este elemento pertence a pelo menos um conjunto" << endl;
                else
                    cout << "Este elemento não pertence a nenhum conjunto" << endl;

                cout << "Voltar ao menu principal? 1 - Sim 0 - Não " << endl;
                cin >> backToPrincipalMenu;

                if(backToPrincipalMenu == 1)
                    menu(set1, set2);
                break;
            }

            case 9: {
                Set *newSet = new Set();
                int min = newSet->min(newSet->unionSet(set1, set2));

                cout << "O menor valor de todos os conjuntos é: " << min << endl;
                cout << "Voltar ao menu principal? 1 - Sim 0 - Não " << endl;
                cin >> backToPrincipalMenu;

                if(backToPrincipalMenu == 1)
                    menu(set1, set2);
                break;
            }

            case 10: {
                Set *newSet = new Set();
                int max = newSet->max(newSet->unionSet(set1, set2));

                cout << "O maior valor de todos os conjuntos é: " << max << endl;
                cout << "Voltar ao menu principal? 1 - Sim 0 - Não " << endl;
                cin >> backToPrincipalMenu;

                if(backToPrincipalMenu == 1)
                    menu(set1, set2);
                break;
            }

            case 11: {
                system("clear");
                cout << "Diferença Simétrica entre os conjuntos A = ";
                set1->print();
                cout << " e B = ";
                set2->print(); 
                cout << " é: C = " ;
                simetricDif(set1, set2);
                
                cout << "Voltar ao menu principal? 1 - Sim 0 - Não " << endl;
                cin >> backToPrincipalMenu;

                if(backToPrincipalMenu == 1)
                    menu(set1, set2);
                break;
            }

            default: {
                cout << "Valor invalido" << endl;
                menu(set1, set2);
                break;
            }
        }
    }
}

int main() {
    Set *set1 = new Set();
    Set *set2 = new Set();

    menu(set1, set2);

    delete set1;
    delete set2;
    return 0;
}