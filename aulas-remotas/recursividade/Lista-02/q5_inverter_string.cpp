#include <iostream>

using namespace std;

void invert_string(char *letter, int size) {
    if(size == 0)
        return;
    cout << letter[size-1];
    invert_string(letter, size-1);
}

int main() {
    int size = 0;
    cin >> size;

    char *letter = new char[size];
    for(int i = 0; i < size; i++)
        cin >> letter[i];
    invert_string(letter, size);

    delete[] letter;

    return 0;
}