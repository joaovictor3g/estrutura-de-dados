#include <iostream>

using namespace std;

int contar_letra(char *palavra, int size, char elemento) {
    if(size == 0)
        return 0;
    if(palavra[size-1] == elemento)
        return contar_letra(palavra, size-1, elemento) + 1;
    return contar_letra(palavra, size-1, elemento);
}

int main() {
    int size = 0;
    cin >> size;

    char *palavra = new char[size];
    for(int i = 0; i < size; i++)
        cin >> palavra[i];
    
    char elemento;
    cin >> elemento;

    cout << contar_letra(palavra, size, elemento);

    delete[] palavra;
    return 0;
}