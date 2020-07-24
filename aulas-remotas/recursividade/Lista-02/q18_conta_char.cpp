// Escreva uma fun¸c˜ao recursiva que recebe como entrada uma string e um caractere c
// e retorna a quantidade de vezes que c apareceu na string.

#include <iostream>

using namespace std;

int count_char(char *arr, int size, char caracter) {
    if(size==0)
        return 0;
    if(arr[size-1]==caracter) 
        return count_char(arr, size-1, caracter)+1;
    return count_char(arr, size-1, caracter);
}

int main() {
    int size{0};
    char caracter;
    cin >> size;

    char *arr_string = new char[size];
    for(int i = 0; i< size; i++)
        cin >> arr_string[i];
    cin >> caracter;

    cout << count_char(arr_string, size, caracter) << endl;

    return 0;
}