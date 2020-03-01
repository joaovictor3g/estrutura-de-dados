#include <iostream>
#include <iomanip>
#include <cstdlib>

int main() {
    int freq1 = 0, freq2 = 0, freq3 = 0, freq4 = 0, freq5 = 0, freq6 = 0, face = 0; 

    for(int roll = 0; roll <= 6000000; roll++) {
        face = 1 + std::rand() % 6;

        switch (face) {
            case 1: 
                ++freq1;
                break;
    
            case 2: 
                ++freq2;
                break;
    
            case 3:
                ++freq3;
                break;
    
            case 4:
                ++freq4;
                break;
    
            case 5:
                ++freq5;
                break; 

            case 6:
                ++freq6;
                break;

            default:
                std::cout << "The program should never get here!" << std::endl;
                break;
        }
    }
    std::cout << "Face" << std::setw(13) << "Frequency" << std::endl;
    std::cout << "   1" << std::setw(13) << freq1
            << "\n   2" << std::setw(13) << freq2
            << "\n   3" << std::setw(13) << freq3
            << "\n   4" << std::setw(13) << freq4
            << "\n   5" << std::setw(13) << freq5
            << "\n   6" << std::setw(13) << freq6 << std::endl;

    return 0;
}
