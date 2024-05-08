#include <iostream>
#include <locale.h>

int main(int argc, char** argv) {
    char* infilename = argv[1], * outfilename = argv[2];

    if (argc < 3) {
        std::cout << "Incorrect arguments" << std::endl;
        return 0;
    }

    setlocale(LC_ALL, "Rus");
        
    std::cout << "infilename: " << infilename << std::endl;
    std::cout << "outfilename: " << outfilename << std::endl;

    return 0;
}