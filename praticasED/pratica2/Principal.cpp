#include <iostream>
#include "ListaDinEncad.hpp"

using namespace std;

int main() {
    Lista *li;

    li = cria_lista();
    libera_lista(li);

    return 0;
}