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

void menu(Set *set1, Set *set2) {
    int option = 0;
    cout << "1 - Adicionar ao conjunto 1        2 - Adicionar ao conjunto 2" << endl;
    cout << "3 - Unir os dois conjuntos         4 - imprimir conjunto" << endl;
    cout << "5 - Interseccão dos conjuntos" << endl;

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

            default: {
                cout << "Valor invalido" << endl;
                menu(set1, set2);
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