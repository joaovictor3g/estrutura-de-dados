#include <iostream>
#define MAX 20
#include "List.h"

using namespace std;

int main() {
    List list(MAX);

    list.add(100000);
    list.add(1);
    list.add(-79);
    list.add(87);
    list.add(-897);
    list.add(90877);

    cout << list.getMinValue() << endl;
    list.print();

    list.removeMaxValue();
    list.print();

    list.remove(-79);
    list.remove(87);
    list.print();

    list.add(75);
    list.add(75);
    list.add(54);
    list.add(75);
    list.add(76);
    list.add(75);
    list.add(80);
    cout << "Quantidade de 75s " << list.countElement(75) << endl;
    list.print();

    list.removeAt(75);
    list.print();

    return 0;
}