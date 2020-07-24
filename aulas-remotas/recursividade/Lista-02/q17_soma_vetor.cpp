//  Fa¸ca uma fun¸c˜ao recursiva que permita somar os elementos de um vetor de inteiros

#include <iostream>

using namespace std;

int sum_in_vector(int *arr, int size) {
    if(size == 0)
        return 0;
    if(size == 1)
        return arr[size-1];
    return arr[size-1] + sum_in_vector(arr, size-1);
}

int main() {
    int size = 0;
    cin >> size;

    int *arr = new int[size];
    for(int i = 0; i < size; i++)
        cin >> arr[i];
    cout << sum_in_vector(arr, size) << endl;

    return 0;
}