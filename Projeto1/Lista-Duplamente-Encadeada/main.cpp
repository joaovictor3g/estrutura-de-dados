#include <iostream>
#include "List.h"

using namespace std;

void menu(List *list) {
    int option = 0;
    cout << "Menu de opções " << endl;
    cout << "1 - Adicionar" << endl;
    cout << "2 - Copiar" << endl;
    cout << "3 - Remover" << endl;
    cout << "4 - Imprimir Lista" << endl;
    cin >> option;

    int value = 0;
    // while(option != 0) {
        switch(option) {
            case 1: {
                cout << "Digite o valor: " << endl;
                cin >> value;
                list->pushBack(value);
                menu(list);
                break;
            }
            case 2: {
                List *list2 = new List();
                list2 = list->copy();
                cout << "Lista copiada" << endl;
                menu(list);
                break;
            }
            case 3: {
                break;
            }
            case 4: {
                list->print();
                break;
            
            }
        }
}

int main() {
    List *list = new List();

    menu(list);

    delete list;
    return 0;
}