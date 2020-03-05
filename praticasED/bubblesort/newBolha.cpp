#include <iostream>

using std::cin;
using std::cout;
using std::endl;

int *ordenacaoPorBolha(int *array, int n) {
    bool ordenado = false;
    while(!ordenado) {
        ordenado = true;
        for(int i = 0; i < n - 1; i++) {
            if(array[i] > array[i+1]) {
                ordenado = false;
                int aux = array[i];
                array[i] = array[i+1];
                array[i+1] = aux;
            }
        }
    }
    return array;
}

int main() {
    int n = 0;
    cin >> n;
    int *array = new int[n];
    
    for(int i = 0; i < n; i++)
        cin >> *(array + i);
    for(int j = 0; j < n; j++)
        cout << *(ordenacaoPorBolha(array, n) + j) << " "; 
    cout << endl;
    
    delete[] array;
    
    return 0;
}