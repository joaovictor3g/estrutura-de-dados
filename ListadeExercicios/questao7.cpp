#include <iostream>
#include <cstring>

using std::cin;
using std::cout;
using std::endl;
using std::getchar;

int main() {
    int size = 10, indice = 0;
    char *arrChar = new char[size];
    
    cout << "Pare digitando ENTER" << endl;

    if(arrChar == nullptr)
        arrChar = new char[size];

    else {
        char *ptr = arrChar + size;
        for(int i = 0; i < size; i++)
            arrChar[i] = getchar();
        

    }
    
    return 0;
}