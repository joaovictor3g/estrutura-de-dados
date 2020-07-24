#include <iostream>

using namespace std;

int fibonnaci(int number) {
    if(number == 1)
        return 0;
    if(number == 2 || number == 3)
        return 1;
    return fibonnaci(number-1)+fibonnaci(number-2);
}

int main() {
    int number = 0;
    cin >> number;

    cout << fibonnaci(number) << endl;

    return 0;
}