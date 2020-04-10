#include <iostream>
#include <stack>

using namespace std;

int main() {
    stack<string> cartas;

    cartas.push("Rei de Copas");
    cartas.push("Rei de Espadas");
    cartas.push("Rei de Ouro");
    cartas.push("Rei de Paus");

    cout << cartas.size() << endl;
    
    cout << cartas.top() << endl;

    cartas.pop();

    cout << cartas.size() << endl;

    cout << cartas.top() << endl;
    
    if(cartas.empty())
        cout << "Empty stack" << endl;
    else {
        cout << "Stack has elements" << endl;
    }

    return 0;
}