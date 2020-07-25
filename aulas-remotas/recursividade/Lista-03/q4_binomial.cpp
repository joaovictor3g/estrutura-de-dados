#include <iostream>

using namespace std;

int coef_binomial(int n, int k) {
    if(k==0 || k==n)
        return 1;
    return coef_binomial(n-1, k-1)+coef_binomial(n-1, k);
}

int main() {
    int n = 0, k = 0;
    cin >> n >> k;

    cout << coef_binomial(n, k) << endl;

    return 0;
}