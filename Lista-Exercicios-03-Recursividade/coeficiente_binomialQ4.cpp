#include <iostream>

using namespace std;

/*
    12, 3 = 12!/3!(9)!
    12 - 3 / 9
*/

int coeficiente_binomial(int n, int k) {
    if(n == 0 || k == 0) 
        return 1;
    return n * coeficiente_binomial(n-1, k-1);
    //else return n;
}
/*
    10, 4
    coef_bin(10, 4) = 10 * coef_bin(9, 3)
    coef_bin(9, 3) = 9 * coef_bin(8, 2)
    coef_bin(8, 2) = 8 * coef_bin(7, 1)

*/
int fatorial_de_k(int k) {
    if(k == 0)
        return 1;
    return k * fatorial_de_k(k-1);
}
/*
    coef_bin(5, 3) = 5 * coef_bin(4, 3) = 5 * 4 * 3 * 2 * 1 * 1
    coef_bin(4, 3) = 4 * coef_bin(3, 3) = 4 * 3 * 2 * 1 * 1
    coef_bin(3, 3) = 3 * coef_bin(2, 3) = 3 * 2 * 1 * 1
    coef_bin(2, 3) = 2 * coef_bin(1, 3) = 2 * 1 * 1
    coef_bin(1, 3) = 1 * coef_bin(0, 3) = 1 * 1
    coef_bin(0, 3) = 1;
  
    k!
*/

int main() {
    int n = 0, k = 0;
    cin >> n >> k;

    cout << coeficiente_binomial(n, k)/fatorial_de_k(k);

    return 0;
}