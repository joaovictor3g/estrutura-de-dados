#include <iostream>

using namespace std;

int fat(int number) {
    if(number == 0 || number == 1)
        return 1;
    return number * fat(number-1);
}

int main() {
    int number = 0;
    cin >> number;

    cout << fat(number) << endl;

    return 0;
}