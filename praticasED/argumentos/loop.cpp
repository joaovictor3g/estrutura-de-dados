#include <iostream>

using namespace std;

void loop(int num, int cont=0);

void loop(int num, int cont){
    cout << cont << " ";
    if(cont % 10 == 0)
        cout << endl;

    if(num > cont)
        loop(num, ++cont);

}

int main() {
    loop(100000);

    return 0;
}