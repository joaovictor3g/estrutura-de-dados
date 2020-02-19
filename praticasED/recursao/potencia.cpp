#include <iostream>

using namespace std;

int potencia(int n){
    if(n == 0)  return 1;
    
    return 2 * potencia(n-1);
}

int main(){
    int n = 0;
    cin >> n;

    cout << potencia(n) << endl;

    return 0;
}