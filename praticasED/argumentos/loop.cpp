#include <iostream>

using namespace std;

void loop(){
    cout << "É recursiva" << endl;
    loop();
}

int main() {
    loop();
    
    return 0;
}