#include <iostream>

using namespace std;

int max_vet(int *v, int n) {
    if(n == 1)
        return 0;
    int s = max_vet(v, n-1);
    if(v[s] > v[n-1])
        return s;
    return n -1;
}

int main() {
    int vet[]{0, 1, 2, 2, 8, 9};
    int i = max_vet(vet, 6);
    cout << vet[i] << endl;

    return 0;
}