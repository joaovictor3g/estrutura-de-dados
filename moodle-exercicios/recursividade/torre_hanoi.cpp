#include <iostream>

using namespace std;

void move_disco(int num, char origem, char destino) {
    cout << origem << " -> " << destino << endl;

}   

void move_torre(int num, char origem, char destino, char aux) {
    if(num == 1)
        move_disco(num, origem, destino);
    else {
        move_torre(num-1, origem, aux, destino);
        move_disco(num, origem, destino);
        move_torre(num-1, aux, destino, origem);
    }
}
/*
    move_torre(3, 'A', 'C', 'B') = 
    move_torre(2, 'A', 'B', 'C')
    move_torre(1, 'A', 'C', 'B') = move_disco(1, 'A', 'B')

*/
int main() {
    int num = 0;
    cin >> num;
    move_torre(num, 'A', 'C', 'B');

    return 0;
}