#include <iostream>
#include <cctype>

using std::cout;
using std::endl;
using std::cin;

using std::islower;
using std::toupper;

//Minuscula em maiuscula
void convertToUpperCase( char* );

//Preenche o array
void fillArray(int *array, int n);

//Mostra o array
void showArray(int *array, int n);

int main() {
    char phrase[]{"Characters and $32.98"};

    cout << "Frase antes da modificação: " << phrase << endl;
    convertToUpperCase(phrase);
    cout << "Frase depois da modificação: " << phrase << endl;

    int *array = new ( std::nothrow ) int[5];

    if(array == nullptr) 
        cout << "Me dê mais espaço" << endl;
    
    else {
        fillArray(array, 5);
        showArray(array, 5);
    }
    delete array;
    array = nullptr;

    return 0;
}

void convertToUpperCase(char *sPtr) {
    while(*sPtr != '\0') {
        if(islower(*sPtr)) 
            *sPtr = toupper(*sPtr);
        *sPtr++;
    }
}

void fillArray(int *array, int n) {
    for(int i = 0; i < n; i++) 
        cin >> *(array+i);
}

void showArray(int *array, int n) {
    for(int i = 0; i < n; i++) 
        cout << *(array + i) << " ";
    cout << endl;
}