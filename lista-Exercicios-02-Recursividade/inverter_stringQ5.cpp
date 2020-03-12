#include <iostream>

using namespace std;

void inverte(char *palavra, int size) {
    if(size == 0)
        return;
    cout << palavra[size-1];
    inverte(palavra, size-1);
}

int main() {
    int size = 0;
    cin >> size;

    char *array = new char[size];
    for(int i = 0; i < size; i++)
        cin >> array[i];

    inverte(array, size);

    delete[] array;
    return 0;
}