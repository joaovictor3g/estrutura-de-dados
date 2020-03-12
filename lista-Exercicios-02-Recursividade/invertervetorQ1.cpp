#include <iostream>

using namespace std;

void inverte(int *array, int size) {
    if(size == 0)
        return;
    cout << array[size-1] << " ";
    inverte(array, size-1);
    
}

int main() {
    int size = 0;
    
    cin >> size;

    int *array = new int[size];
    for(int i = 0; i < size; i++) 
        cin >> array[i];
    inverte(array, size);

    delete[] array;
    return 0;
}