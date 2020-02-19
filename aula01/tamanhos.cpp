#include <iostream>

using std::cout;
using std::string;
using std::endl;

int main() {
    cout << sizeof(int) << " bytes" <<  endl;
    cout << sizeof(double) << " bytes" <<  endl;
    cout << sizeof(char) << " byte" <<  endl;
    cout << sizeof(string) << " bytes" <<  endl;
    cout << sizeof(long) << " bytes" <<  endl;
    cout << sizeof(short) << " bytes" <<  endl;
    cout << sizeof(unsigned int) << " bytes" <<  endl;
    cout << sizeof(short int) << " bytes" << endl;
    
    return 0;
}