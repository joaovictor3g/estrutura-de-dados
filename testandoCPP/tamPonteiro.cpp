#include <iostream>

bool verificarEquivalencia(char *chPtr, char *iPtr) {
    
    chPtr == iPtr ? true : false;

}

int main() {
    char *chPtr;
    int *iPtr;
    
    struct Coisa {
        int a, b, c;
    };
    Coisa *coisaPtr;

    std::cout << sizeof(chPtr) << " bytes" << std::endl;
    std::cout << sizeof(iPtr) << " bytes" <<std::endl;
    std::cout << sizeof(coisaPtr) << " bytes" << std::endl;
 
    if(verificarEquivalencia) 
        std::cout << "São equivalentes" << std::endl;
    else
        std::cout << "Não são equivalentes" << std::endl;

    return 0;
}