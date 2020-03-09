#include <iostream>

using namespace std;

int fib(int num){
    if(num == 0 || num == 1)    return num;
    
    return fib(num-1)+fib(num-2);
    /*
        fibonacci de 5:
            fib(5) = fib(4) + fib(3) = 5 + 3 = 8
            fib(4) = fib(3) + fib(2) = 3 + 2 = 5
            fib(3) = fib(2) + fib(1) = 2 + 1 = 3
            fib(2) = fib(1) + fib(0) = 1 + 1 = 1
            fib(1) = 1
            fib(0) = 1
            1, 1, 3, 5, 8
   
    */      

}

int main(){
    int n = 0;
    cin >> n;

    cout << fib(n) << endl;

    return 0;
}