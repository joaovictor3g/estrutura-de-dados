#include <iostream>

using namespace std;

int fatorial(int num) {
    int res = 1;

    if(num == 0)
        return 1;
    
    for(int i = 1; i <= num; i++) 
        res *= i;
    return res;

}

int main() {
    int num = 0;
    cin >> num;
    cout << fatorial(num) << endl;

    return 0;
}