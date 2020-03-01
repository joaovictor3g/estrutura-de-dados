#include <iostream>
#include <cstring>

int main() {
    char str1[]{"oi gente"};
    char str2[40];
    char str3[40];

    strcpy(str2, str1);

    strcpy(str3, "Cópia bem sucedida");

    std::cout << "string 1: " << str1 << "\nstring 2: " << str2 << std::endl;
    std::cout << "string 3: " << str3 << std::endl;
    std::cout << "tamanho da string 1: " <<  strlen(str1) << std::endl;


    return 0;
}