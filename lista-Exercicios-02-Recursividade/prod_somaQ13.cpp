#include <iostream>

using namespace std;

int produtoSoComSoma(int num1, int num2) {
    if(num1 == 0 || num2 == 0)
        return 0;
	return num1 + produtoSoComSoma(num1, num2 - 1); 

}

int main() {
    int a = 0, b = 0;
    cin >> a >> b;

    int menor = min(a, b);
    int maior = max(a, b);
    cout << produtoSoComSoma(maior, menor) << endl;

    return 0;
}
