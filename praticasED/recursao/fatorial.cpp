#include <iostream>

using namespace std;

int fat(int num){
    if(num == 0 || num == 1)    return 1;

    return num * fat(num-1);
    /*
        fatorial de 5:
            fat(5) = 5 * fat(4) = 5 * 4 * 3 * 2 * 1
            fat(4) = 4 * fat(3) = 4 * 3 * 2 * 1
            fat(3) = 3 * fat(2) = 3 * 2 * 1
            fat(2) = 2 * fat(1) = 2 * 1
        fatorial de 4:
            4 * fat(3) = 4 * 3 * 2 * 1
            3 * fat(2) = 3 * 2 * 1
            2 * fat(1) = 2 * 1
        fatorial de 3:
            3 * fat(2) = 3 * 2 * 1
            2 * fat(1) = 2 * 1
        fatorial de 2:
            2 * fat(1) = 2 * 1

    */
}   

int main(){
    int n = 0;
    cin >> n;

    cout << fat(n) << endl;

    return 0;
}