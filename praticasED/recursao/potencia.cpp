#include <iostream>

using namespace std;

int potencia(int base, int n){
    if(n == 0)  return 1;
    
    return base * potencia(base, n-1);
}

int main(){
    int n = 0;
    cin >> n;

    cout << potencia(7, n) << endl;

    return 0;
}