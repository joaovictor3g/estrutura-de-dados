#include <iostream>
#include "lib/copiarStrings.h"

char *strcpy(char *destino, char *origem) {
    
    for(int i = 0; origem[i]; i++) 
        destino[i] = origem[i];
    return destino;
}

int strcmp(char *str1, char *str2) {
    int cont1{0}, cont2{0};

    while(str1[cont1])  cont1++;
    while(str2[cont2])  cont2++;

    if(cont1 == cont2)  
        return 0;

    else if(cont1 < cont2)  
        return -1;
    return 1;
}

int main() {
    char str1[]{"Ola gente"};
    char str2[40];

    std::cout << strcpy(str2, str1) << std::endl;

    char str3[]{"olá"};
    char str4[]{"ola"};
    std::cout << strcmp(str3, str4) << std::endl;
    
    
    return 0;
}
