#include <iostream>

using namespace std;

int *aloc(int n) {
    int *vetor;
    if(n <= 0)
        vetor = nullptr;
    else vetor = new ( nothrow ) int[n];

    return vetor;
}

int main() {
    int n = 0;
    cin >> n;
    int *arr = aloc(n);
    if(arr != nullptr) {
        cout << "Alocação bem-sucedida" << endl;
    }
    else {
        cout << "Alocação incorreta" << endl;
    }

    delete[] arr;
    
    return 0;
}