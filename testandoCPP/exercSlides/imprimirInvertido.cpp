#include <iostream>

int main() {
    int n = 0;
    std::cin >> n;

    int *vetor = new int[n];

    for(int i = 0; i < n; i++)      std::cin >> *(vetor+i);

    for(int j = n - 1; j >= 0; j--)      std::cout << *(vetor+j) << " ";

    std::cout << "\n";


    return 0;
}