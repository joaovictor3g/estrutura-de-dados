#include <iostream>

int main() {
    enum class Color { RED, BLUE };
    enum Fruit { BANANA, APPLE };

    Color cor = Color::RED;
    Fruit fruit = Fruit::BANANA;
    
    //Erro de compilação
    if(cor == fruit)
        std::cout << "Cor e fruta são iguais" << std::endl;
    else
        std::cout << "Cor e fruta são diferentes" << std::endl;

    return 0;
}
