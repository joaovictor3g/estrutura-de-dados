#include <iostream>

using namespace std;

int fat(int num){
    if(num == 0 || num == 1)    return 1;

    return num * fat(num-1);

}   

int main(){
    int n = 0;
    cin >> n;

    cout << fat(n) << endl;

    return 0;
}