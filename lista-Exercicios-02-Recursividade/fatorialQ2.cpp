#include <iostream>

using namespace std;

int fat(int num) {
    if(num == 1 || num == 0)    return 1;
    return num * fat(num-1);
}

int main() {
    int num = 0;
    cin >> num;
    cout << fat(num) << endl;

    return 0;
}