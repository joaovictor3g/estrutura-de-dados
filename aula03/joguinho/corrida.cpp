#include <iostream>
#include <cstdlib>

using std::srand;
using std::rand;
using std::cout;
using std::endl;



int main() {
    srand( time (NULL) );

    enum typeMovementsTurtle { 
        CAMINHADARAPIDA,
        ESCORREGAO,
        CAMINHADALENTA, 
        
    };

    enum typeMovementesHare {
        PARADA,
        SALTOGRANDE,
        ESCORREGAOGRANDE,
        SALTOPEQUENO,
        ESCORREGAOPEQUENO
    };

    typeMovementsTurtle turtle;
    typeMovementesHare hare;

    int *caminho = new int[40];
    int indice = 0, posTurtle = 0, posHare = 0;
    char *TurtleWay = new char[40];
    char *HareWay = new char[40];

    cout << "BANG !!!!! \nAND THEY'RE OFF !!!! \n";
    
    for(int i = 0; i < 70; i++) 
        cout << "--";
    cout << endl;

    while(posTurtle < 40 && posHare < 40) {
        turtle = (typeMovementsTurtle) (rand() % 3);
        hare = (typeMovementesHare) (rand() % 5);
        
        if(turtle == CAMINHADARAPIDA) {
            posTurtle += 3;
            
        
        } else if(turtle == ESCORREGAO) {
            posTurtle -= 6;
            if(posTurtle < 0)
                posTurtle = 0;
            

        } else if(turtle == CAMINHADALENTA){
            posTurtle++;
        
        
        }
        if(hare == PARADA) {
            posHare = 0;
            

        } else if(hare == SALTOGRANDE) {
            posHare += 9;
            
        
        } else if(hare == ESCORREGAOGRANDE) {
            posHare -= 12;
            if(posHare < 0)
                posHare = 0;
            

        } else if(hare == SALTOPEQUENO) {
            posHare++;
           
        
        } else if(hare == ESCORREGAOPEQUENO) {
            posHare += 2;
            
        }
        if(posTurtle == posHare) {
            cout << "OUCH !!!";

        } 
    }
    cout << "\n \n";
    for(int i = 0; i < 70; i++) 
        cout << "__";

    if(posHare > posTurtle) {
        cout << "\nHare wins. Yuch." << endl;
    
    } else if(posTurtle > posHare) {
        cout << "\nTortoise wins !!!! YAY !!!" << endl;

    } else {
        cout << "\nIt's a tie." << endl;
    }


    delete[] caminho;
    delete[] TurtleWay;
    delete[] HareWay;

    caminho = nullptr;
    TurtleWay = nullptr;
    HareWay = nullptr;

    return 0;
}