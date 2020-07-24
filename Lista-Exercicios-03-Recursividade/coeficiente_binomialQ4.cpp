#include <iostream>

using namespace std;

/*
    12, 3 = 12!/3!(9)!
    12 - 3 / 9
*/

int coeficiente_binomial(int n, int k) {
    if(k == 0 || k == n) 
        return 1;
    return coeficiente_binomial(n-1, k-1) + coeficiente_binomial(n-1, k);
    //else return n;
}
/*
    6, 4
    coef(6, 4) = coef(5, 3) + coef(5, 4)
    coef(5, 3) = coef(4, 2) + coef(4, 3)
    coef(4, 2) = coef(3, 1) + coef(3, 2)
    coef(3, 1) = coef(2, 0) + coef(2, 1) = 1 + coef(2, 1)
    coef(2, 1) = coef(1, 0) + coef(1, 1) = 1 + coef(1, 1)
    coef(1, 1) = coef(0, 0) + coef(0, 1) = 1 + coef(0, 1)
    coef(0, 1) = 
*/

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

    cout << coeficiente_binomial(n, k);

    return 0;
}