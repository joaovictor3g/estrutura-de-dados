#include <iostream>

using std::cin;
using std::cout;
using std::endl;

int strcmp(char *str1, char *str2) {
    int counter1 = 0, counter2 = 0;
    
    //enquanto !'\0' incrementa
    while(*str1++)  counter1++;
    while(*str2++)  counter2++;

    cout << counter1 << counter2;
    if(counter1 == counter2) return 0;
    else if(counter1 > counter2)    return 1;
    else  return -1;
    
}

int main() {
    char str1[1000];
    char str2[1000]{"Olá mundo"};

    cout << strcmp(str1, str2) << endl;

    return 0;
}