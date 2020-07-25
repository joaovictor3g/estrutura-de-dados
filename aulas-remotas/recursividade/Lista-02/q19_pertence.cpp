//  Fa¸ca uma fun¸c˜ao recursiva que recebe um vetor ordenado e um inteiro x e retorna 1
// se x pertencer ao vetor e 0 caso contr´ario.
// Seu programa deve ter complexidade da ordem de log n.

#include <iostream>

using namespace std;

int verify_if_exists(int *arr, int size, int x) {
    if(size == 0)
        return 0;
    if(arr[size-1]==x)
        return 1;
    return verify_if_exists(arr, size-1, x);
}

int main() {
    int size = 0, x = 0;
    cin >> size;

    int *arr = new int[size];
    for(int i = 0; i < size; i++)
        cin >> arr[i];
    cin >> x;

    if(verify_if_exists(arr, size, x)) {
        cout << "O número " << x << " pertence ao vetor [";
        for(int i = 0; i < size; i++) i == size-1 ? cout<< arr[i] : cout<< arr[i] << ", "; 
        cout << "]";
    }else{
        cout << "O número " << x << " não pertence ao vetor [";
        for(int i = 0; i < size; i++) i == size-1 ? cout<< arr[i] : cout<< arr[i] << ", ";  
        cout << "]";
    }
    delete[] arr;

    return 0;
}