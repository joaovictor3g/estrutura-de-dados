#include <iostream>
#include "List.h"

using namespace std;

void addList(List *list, int key) {
    list->pushBack(key);
    cout << "Chave adicionada com sucesso" << endl;
}

void print(List *list) {
    cout << "Sua lista atual:" << endl;
    list->print();
}

void printReverse(List *list) {
    cout << "Sua lista atual:" << endl;
    list->printReverse();
}

void removeLastKey(List *list) {
    cout << "Última chave: " << list->popBack() << " removida com sucesso!!!" << endl;
}

void insertAfterIndex(List *list, int key, int index) {
    list->insertAfter(key, index);
    cout << "Valor: " << key << " adcionado apó o indice: " << index << endl;
}

void removeSpecificKey(List *list, int key) {
    if(!list->contains(key)) {
        cout << "CHAVE INEXISTENTE!!!" << endl;
        return;
    }
    list->remove(key);
    cout << "Chave: [" << key << "] removida com sucesso!!!" << endl;
}

void menu(List *list) {
    int option = 0;
    cout << "1 - Adicionar uma chave            2 - Imprimir Lista" << endl;
    cout << "3 - Remover a última chave         4 - Inserir após um índice" << endl;
    cout << "5 - Remover uma chave especifica   6 - Remover todas as chaves com um nó específico"  << endl;

    cin >> option;
    int backToPrincipalMenu = 0;

    while(true) {
        switch(option) {
            case 1: {
                int key = 0;
                cout << "Digite o valor da chave: " << endl;
                cin >> key; 
                addList(list, key);
                system("clear");
                cout << "Voltar ao menu principal? 1 - Sim 0 - Não " << endl;
                cin >> backToPrincipalMenu;

                if(backToPrincipalMenu == 1)
                    menu(list);
                break;
            }

            case 2: {
                int choice = 0;
                cout << "1 - Imprimir Lista Normal      2 - Imprimir lista ao contrário" << endl;
                cin >> choice;
                
                system("clear");
                if(choice == 1)     print(list);
                else if(choice == 2)    printReverse(list);
                else    cout << "Valor inválido" << endl;
                
                cout << "Voltar ao menu principal? 1 - Sim 0 - Não " << endl;
                cin >> backToPrincipalMenu;

                if(backToPrincipalMenu == 1)
                    menu(list);
                break;
            }

            case 3: {
                system("clear");
                removeLastKey(list);
                cout << "Voltar ao menu principal? 1 - Sim 0 - Não " << endl;
                cin >> backToPrincipalMenu;

                if(backToPrincipalMenu == 1)
                    menu(list);
                break;
            }

            case 4: {
                int key = 0;
                int index = 0;
                cout << "Digite o novo valor a ser adicionado: " << endl;
                cin >> key;
                cout << "Após qual índice? Indice no intervalo de: 0 a " << list->size() << endl;
                cin >> index;
                system("clear");

                insertAfterIndex(list, key, index);
                cout << "Voltar ao menu principal? 1 - Sim 0 - Não " << endl;
                cin >> backToPrincipalMenu;

                if(backToPrincipalMenu == 1)
                    menu(list);
                break;

            }

            case 5: {
                system("clear");
                print(list);
                int keyToRemove = 0;
                cout << "Qual chave remover? " << endl;
                cin >> keyToRemove;

                system("clear");
                removeSpecificKey(list, keyToRemove);
                print(list);
                cout << "Voltar ao menu principal? 1 - Sim 0 - Não " << endl;
                cin >> backToPrincipalMenu;

                if(backToPrincipalMenu == 1)
                    menu(list);
                break;
            }

            default: {
                break;
            }
        }
    }
}

int main() {
    List *list = new List();
    
    menu(list);
 
    delete list;
    return 0;
}