#include <iostream>

using namespace std;

int produtoSoComSoma(int num1, int num2) {
    int menor = min(num1, num2);
    int maior = max(num1, num2);
    int soma = 0;

   if(maior >= menor) 
	return produtoSoComSoma(num1+num2, menor); 
  
}

int main() {
    int a = 0, b = 0;
    cin >> a >> b;

    cout << produtoSoComSoma(a, b) << endl;

    return 0;
}
