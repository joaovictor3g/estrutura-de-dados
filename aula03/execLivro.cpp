#include <iostream>
#include <iomanip>
#define SIZE 10

using namespace std;

int main() {
    double numbers[SIZE]{0.0, 1.1, 2.2, 3.3, 4.4, 5.5, 6.6, 7.7, 8.8, 9.9};
    double *nPtr = nullptr, *otherPtr = nullptr;

    otherPtr = numbers;
    cout << fixed << setprecision(1);
    for(int i = 0; i < SIZE; i++) 
        cout << numbers[i] << " ";
    cout << endl;

    nPtr = numbers;
    for(int i = 0; i < SIZE; i++) 
        cout << *(nPtr + i) << " ";
    cout << endl;

    for(int i = 0; i < SIZE; i++)
        cout << *(numbers + i) << " ";
    cout << endl;

    for(int i = 0; i < SIZE; i++) 
        cout << nPtr[i] << " ";
    cout << endl;

    nPtr = &numbers[3];
    cout << *nPtr << endl;
    nPtr = (numbers + 3);
    cout << *nPtr << endl;
    nPtr = &numbers[5];
    cout << *(nPtr -= 4) << endl;
    
    return 0;
}