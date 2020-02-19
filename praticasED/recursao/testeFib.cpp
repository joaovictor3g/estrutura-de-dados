#include <iostream>

using namespace std;

int fib(int num){
    if(num == 0 || num == 1)    return num;
    
    return fib(num-1)+fib(num-2);
}

int main(){
    int n = 0;
    cin >> n;

    for(int i = 0; i <= n; i++)     cout << fib(i) << " ";
    cout << endl;

    return 0;
}