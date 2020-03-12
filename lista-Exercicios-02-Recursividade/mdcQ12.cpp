#include <iostream>

using namespace std;

int mdcEuc(int m, int n){
    int dividendo = m, divisor = n;

    if(divisor == 0)     return dividendo;
    if(dividendo%divisor == 0)      return divisor;
    return mdcEuc(divisor, dividendo%divisor);

}

int main() {
    int m = 0, n = 0;
    cin >> m >> n;

    cout << mdcEuc(m, n) << endl;

    return 0;
}