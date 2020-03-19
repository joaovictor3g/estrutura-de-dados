#include <iostream>

using namespace std;

int mult_russa(int num1, int num2) {
    if(num1 == 0 || num2 == 0)
        return 0;
    
    if(num1 % 2 == 0)
        return mult_russa(num1/2, num2*2);
    num1--;
    return mult_russa(num1/2, num2*2) + num2;
    
}

int main() {
    int num1 = 0, num2 = 0;
    cin >> num1 >> num2;

    cout << mult_russa(num1, num2);

    return 0;
}