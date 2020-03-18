#include <iostream>

using namespace std;

int verifica_soma(int *arr, int size, int value) {
    if(size == 1)
        return 0;

    if(size == 2 && value == arr[size-1] + arr[size-2])
        return 1;
    else 
        return 0;

    if(value < arr[size-1]) {
        if(value == arr[size-1] + arr[size-2])
            return  1;
        return verifica_soma(arr, size-1, value);
    }
    return verifica_soma(arr, size-1, value);
    /*
        vetor: -1, 6, 7| size:3| value: 5

    */

}

int main() {
    int size = 0, value;
    cin >> size;

    int *array = new int[size];
    for(int i = 0; i < size; i++) 
        cin >> array[i];
    cin >> value;
    
    if(verifica_soma(array, size, value) == 1)
        cout << "SIM" << endl;
    else 
        cout << "NÃO" << endl;

    return 0;
}