/*Um jogador rola dois dados. Cada dado tem seis faces. 
Essas faces contêm 1, 2, 3, 4, 5 e 6 pontos. 
Depois que os dados param de rolar, a soma dos pontos nas faces viradas para cima é calculada. 
Se a soma é 7 ou 11 na primeira rolagem dos dados, o jogador ganha. 
Se a soma é 2, 3 ou 12 na primeira rolagem dos dados (chamado ‘craps’), o jogador perde (isto é, a ‘casa’ ganha). 
Se a soma for 4, 5, 6, 8, 9 ou 10 na primeira rolagem dos dados, essa soma torna-se a ‘pontuação’ do jogador. 
Para ganhar, você deve continuar a lançar o dado até ‘fazer sua pontuação’. 
O jogador perde se obtiver um 7 antes de fazer sua pontuação.*/

#include <iostream>
#include <cstdlib>

int rollDice();

int rollDice() {
    int roll1 = 1 + std::rand() % 6;
    int roll2 = 1 + std::rand() % 6;

    std::cout << "Player rolled: " << roll1 << " + " << roll2 << " = " << roll1 + roll2 << std::endl;

    return roll1 + roll2;
}

int main() {
    std::srand(time(NULL));

    enum Status { CONTINUE, WON, LOST };
    int score = 0;

    Status gameStatus;

    int sumOfDice = rollDice();

    switch ( sumOfDice ){
        case 7:
        case 11:
            gameStatus = WON;
            break;
        case 2:
        case 3:
        case 12:
            gameStatus = LOST;
            break;  
        default:
            score = sumOfDice;
            gameStatus = CONTINUE;
            break;
    }

    while (gameStatus == CONTINUE) {
        sumOfDice = rollDice();

        if(sumOfDice == score) 
            gameStatus = WON;

        else if(sumOfDice == 7) 
            gameStatus = LOST;

    }
    if(gameStatus == WON) 
        std::cout << "Player wins" << std::endl;
    else 
        std::cout << "Player loses" << std::endl;

    return 0;
}