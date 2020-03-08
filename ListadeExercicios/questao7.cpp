#include <iostream>
#include <cstring>
#include <cstdio>

using std::cin;
using std::cout;
using std::endl;

int main() {
    int size = 10, indice = 0;
    char *first_array = new char[size];
    char *third_array = nullptr;

    while((first_array[indice] = getchar()) != '\n') {
        indice++;
        if(indice >= size) {
            size += 10;
            third_array = new char[size];
            
            for(int i = 0; i < size - 10; i++)
                third_array[i] = first_array[i];
			
            delete[] first_array;
            first_array = new char[size];

            for(int i = 0; i < size - 10; i++)
                first_array[i] = third_array[i];
			
            delete[] third_array;
            third_array = nullptr;
        }
    }

    for(int i = 0; first_array[i]; i++)
		cout << first_array[i];
    delete[] first_array;
    first_array = nullptr;
    
    return 0;
}
