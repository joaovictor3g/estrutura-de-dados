#include <iostream>
#include <cstring>

using std::cin;
using std::cout;
using std::endl;
using std::getchar;
using std::putchar;

int main() {
    int size = 10, indice = 0;
    char *first_array = new char[size];
    char *third_array = new char[1000000];

    while((first_array[indice] = getchar()) != '\n') {
        indice++;
        
        if(indice >= size) {
            int i = 0;
            size += 10;
            third_array = new char[size];
        
            for(; first_array[i]; i++) 
                third_array[i] = first_array[i];
            first_array[++i] = '\0';
            
            if(i == 10)     
                delete[] first_array;
            
        }
    }

    if(indice < size) {
        first_array[++indice] = '\0';
        
        for(int i = 0; first_array[i]; i++) 
            cout << first_array[i];
            
    }

    if(third_array != nullptr) {
        third_array[++indice] = '\0';
        
        for(int i = 0; third_array[i]; i++)
            cout << third_array[i]; 
        cout << endl;

    }


    return 0;
}