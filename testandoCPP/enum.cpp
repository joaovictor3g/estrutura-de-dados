#include <iostream>

enum semana {
    Domingo, Segunda, Terca,
    Quarta, Quinta, Sexta,
    Sabado
};

int main() {
    enum semana s1, s2, s3;
    s1 = Segunda;
    s2 = Terca;
    s3 = (semana) (s1 + s2);

    std::cout << "Domingo = " << Domingo << "\n";
    std::cout << "s1 = " << s1 << "\n";
    std::cout << "s2 = " << s2 << "\n";
    std::cout << "s3 = " << s3 << "\n";


    return 0;
}