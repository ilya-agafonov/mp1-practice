#include <iostream>
#include <locale.h>
#include "StoreLib.h"
#include "store.h"

int main(int argc, char** argv) {
    char* infilename = argv[1], * outfilename = argv[2];
    int answer;
    StoreLib storelib;

    if (argc < 3) {
        std::cout << "Incorrect arguments" << std::endl;
        return 0;
    }

    setlocale(LC_ALL, "Rus");
        
    std::cout << "infilename: " << infilename << std::endl;
    std::cout << "outfilename: " << outfilename << std::endl;

    std::ifstream A;
    std::ofstream B;

    switch (answer) {
    case 1:
        A.open(infilename);
        if (!A.is_open()) {
            std::cout << "file A not open" << std::endl;
        }
        A >> storelib;
        A.close();

        B.open(outfilename);
        if (!B.is_open()) {
            std::cout << "file B not open" << std::endl;
        }
        B << storelib << std::endl;
        B.close();
        break;
    case 2:

        break;
    default:
        throw "Incorrect in";
        break;
    }

    return 0;
}