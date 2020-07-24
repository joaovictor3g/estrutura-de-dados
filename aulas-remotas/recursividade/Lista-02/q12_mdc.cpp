//  O m´aximo divisor comum dos inteiros x e y ´e o maior inteiro que ´e divis´ıvel por x e
// y. Escreva uma fun¸c˜ao recursiva mdc, que retorna o m´aximo divisor comum de x e
// y. O mdc de x e y ´e definido como segue: se y ´e igual a 0, ent˜ao mdc(x, y) ´e x; caso
// contr´ario, mdc(x, y) ´e mdc(y, x%y), onde % ´e o operador resto.

#include <iostream>

using namespace std;

int mdc(int x, int y) {
    if(y == 0)
        return x;
    return mdc(y, x%y);
}

int main() {
    int x = 0, y = 0;
    cin >> x >> y;

    cout << mdc(x, y) << endl;

    return 0;
}