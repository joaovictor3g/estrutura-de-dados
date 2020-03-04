#include <iostream>
#include <cstring>

using std::strncpy;
using std::strlen;
using std::strtok;
using std::strcmp;
using std::strcpy;

int main() {
    double n1 = 7.3, n2 = 0;
    char s1[100]{","};
    char s2[100]{"this,is,a,string"};
    char *tokenptr = strtok(s2, ",");
    //item a e b
    double *ftpr = &n1;

    //item c
    std::cout << *ftpr << std::endl; 

    //item d
    n2 = *ftpr;

    //item e
    std::cout << n2 << std::endl;

    //item f
    std::cout << &n1 << std::endl;

    //item g. SIM
    std::cout << ftpr << std::endl;

    //item i
    std::cout << strcmp(s1, s2) << std::endl;

    //item j
    std::cout << strncpy(s1, s2, 10) << std::endl;

    //item l
    while(tokenptr != nullptr) {
        std::cout << tokenptr << " ";
        tokenptr = strtok(nullptr, ",");
    }
    std::cout << std::endl;

    //item h
    std::cout << strcpy(s1, s2) << std::endl;

    //item k
    std::cout << strlen(s1) << std::endl;

    

    return 0;
}