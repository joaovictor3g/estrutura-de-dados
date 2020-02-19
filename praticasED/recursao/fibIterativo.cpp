#include <iostream>

using namespace std;

int fib(int n){
    if(n == 0 || n == 1)    return n;

    int fant = 0, fpos = 1, f = 0; 
    for(int i = 2; i <= n; i++){
        f = fant+fpos;
        fant = fpos;
        fpos = f;

    }
    return f;
}

int main(){
    int num = 0;
    cin >> num;

    for(int i = 0; i <= num; i++)
        cout << fib(i) << " ";
    cout << endl;
    
    return 0;
}