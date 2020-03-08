#include <iostream>

using std::cin;
using std::cout;
using std::endl;

void preencherArray(int A[], int n);

void mm(int A[], int n, int *min, int *max);

int main() {
    int n = 0, minimo = 0, maximo = 0;
    cin >> n;
    int *array = new int[n];
    
    preencherArray(array, n);
    mm(array, n, &minimo, &maximo);
    cout << "O valor minímo é: " << minimo << " o valor máximo é: " << maximo << endl;

    delete[] array;
    array = nullptr;

    return 0;
}

void preencherArray(int A[], int n) {
    for(int i = 0; i < n; i++)  
        cin >> A[i];
}

void mm(int A[], int n, int *min, int *max) {
    *min = A[0]; 
    *max = *min;

    for(int i = 0; i < n; i++) {
        if(*min >= A[i])    *min = A[i];

        if(*max <= A[i])   *max = A[i];
 
    }
}