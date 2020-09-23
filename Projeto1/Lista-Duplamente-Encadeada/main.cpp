#include <iostream>
#include <climits>
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

void removeAllSpecificKey(List *list, int key) {
    if(!list->contains(key)) {
        cout << "CHAVE INEXISTENTE!!!" << endl;
        return;
    }
    list->removeAll(key);
    cout << "Todas as chaves com valor " << key << " removidas!" << endl;
}

int ListSize(List *list) {
    return list->size();
}

void removeNodeAtSpecificIndex(List *list, int index) {
    int key = list->removeNodeAt(index);
    
    if(key == INT_MIN) {
        cout << "Indice inexistente" << endl;
        return;
    }
    cout << "O valor: " << key << " que estava na posição " << index << " foi removido!!!" << endl;
    return;
}

void concatTwoLists(List *list, List *list2) {
    list->concat(list2);
    cout << "Listas concatenadas" << endl;
}

void merge(List *list, List *list2) {
    cout << "Resultado do merge: ";
    list->mergeLists(list2);
}

void menu(List *list) {
    int option = 0;
    cout << "1 - Adicionar uma chave            2 - Imprimir Lista" << endl;
    cout << "3 - Remover a última chave         4 - Inserir após um índice" << endl;
    cout << "5 - Remover uma chave especifica   6 - Remover todas as chaves com um nó específico"  << endl;
    cout << "7 - Tamanho da lista               8 - Remover chave em um índice específico" << endl;
    cout << "9 - Concatenar duas listas         10 - Copiar de um array" << endl;
    cout << "11 - Fundir duas listas" << endl;

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

            case 6: {
                system("clear");
                print(list);
                int keyToRemove = 0;
                cout << "Qual chave remover? " << endl;
                cin >> keyToRemove;

                system("clear");
                removeAllSpecificKey(list, keyToRemove);
                print(list);
                cout << "Voltar ao menu principal? 1 - Sim 0 - Não " << endl;
                cin >> backToPrincipalMenu;

                if(backToPrincipalMenu == 1)
                    menu(list);
                break;
            }

            case 7: {
                system("clear");
                cout << "Tamanho atual da lista: " <<  ListSize(list) << endl;
                cout << "Voltar ao menu principal? 1 - Sim 0 - Não " << endl;
                cin >> backToPrincipalMenu;

                if(backToPrincipalMenu == 1)
                    menu(list);
                break;
            }

            case 8: {
                system("clear");
                int index = 0;
                cout << "Digite qual indice que contém o valor a remover" << endl;
                cin >> index;

                removeNodeAtSpecificIndex(list, index);
                cout << "Voltar ao menu principal? 1 - Sim 0 - Não " << endl;
                cin >> backToPrincipalMenu;

                if(backToPrincipalMenu == 1)
                    menu(list);
                break;
            }

            case 9: {
                system("clear");
                cout << "Uma nova lista será criada para concatenar com a primeira" << endl;
                List *list2 = new List();

                int size = 0;
                cout << "Digite o tamanho da nova lista: "<< endl;
                cin >> size;

                cout << "Digite os " << size << " valores"<< endl;
                int key = 0;
                
                for(int i = 0; i < size; i++) {
                    cin >> key;
                    list2->pushBack(key);
                }
                concatTwoLists(list, list2);
                print(list);
                cout << "Voltar ao menu principal? 1 - Sim 0 - Não " << endl;
                cin >> backToPrincipalMenu;

                if(backToPrincipalMenu == 1)
                    menu(list);
                break;
            }

            case 10: {
                int size = 0;
                cout << "Digite a quantidade de números que deseja adicionar" << endl;
                cin >> size;
                int vec[size];
                cout << "Digite os " << size << " valores agora" << endl;
                for(int i = 0; i < size; i++) 
                    cin >> vec[i];

                list->copyArray(vec, size);
                cout << "Voltar ao menu principal? 1 - Sim 0 - Não " << endl;
                cin >> backToPrincipalMenu;

                if(backToPrincipalMenu == 1)
                    menu(list);
                break;
            }

            case 11: {
                system("clear");
                print(list);
                cout << "Uma nova lista será criada para fundir(merge) com a primeira" << endl;
                List *list2 = new List();

                int size = 0;
                cout << "Digite o tamanho da nova lista: "<< endl;
                cin >> size;

                cout << "Digite os " << size << " valores"<< endl;
                int key = 0;
                
                for(int i = 0; i < size; i++) {
                    cin >> key;
                    list2->pushBack(key);
                }
                list->mergeLists(list2);
                
                cout << "Voltar ao menu principal? 1 - Sim 0 - Não " << endl;
                cin >> backToPrincipalMenu;
                if(backToPrincipalMenu == 1)
                    menu(list);
                break;
            }

            default: {
                cout << "Valor invalido!!!" << endl; 
                menu(list);
                break;
            }
        }
    }
}

int main() {
    List *list = new List();
    
    menu(list);
    // list->pushBack(1);
    // list->pushBack(2);
    // list->pushBack(3);
    // list->pushBack(4);
    // List *list2 = new List();
    // list2->pushBack(-1);
    // list2->pushBack(-2);

    // list->mergeLists(list2);
    // list->print();
 
    delete list;
    return 0;
}