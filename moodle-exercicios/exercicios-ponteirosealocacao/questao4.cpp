#include <iostream>

using namespace std;

int main() {
    int n = 0;

    while(n <= 0)
        cin >> n;
    int *v = new int[n];
    for(int i = 0; i < n; i++) {
        cin >> v[i];
        while(v[i] < 2) {
            cout << "Valor menor que 2 digite novamente: " << endl;
            cin >> v[i];
        }
    }
    for(int i = 0; i < n; i++)
        cout << v[i] << " ";
    cout << endl;

    delete[] v;
    return 0;
}