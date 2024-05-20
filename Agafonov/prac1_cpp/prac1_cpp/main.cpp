#include <iostream>
#include <fstream>
#include <locale>
#include "StoreLib.h"

int main(int argc, char** argv) {
    //system("chcp 1251");
    char* infilename = argv[1], * outfilename = argv[2];
    int answer;
    StoreLib storelib, lib24;

    if (argc < 3) {
        std::cout << "Incorrect arguments" << std::endl;
        return 0;
    }

    std::setlocale(LC_ALL, "Rus");

    std::ifstream infile(infilename);
    if (!infile.is_open()) {
        std::cout << "Input file not open" << std::endl;
        return 1;
    }

    std::ofstream outfile(outfilename);
    if (!outfile.is_open()) {
        std::cout << "Output file not open" << std::endl;
        infile.close();
        return 1;
    }

    std::cout << "��� �������? (1 - ��� ��������, 2 - �������������� ��������)" << std::endl;
    while (!(std::cin >> answer) || (answer != 1 && answer != 2)) {
        std::cout << "�������� ����" << std::endl;
        std::cin.clear(); 
    }
    switch (answer) {
    case 1:
        infile >> storelib;
        infile.close();

        outfile << storelib;
        outfile.close();
        std::cout << "� ���� fileout.txt ���������� ��� ��������" << std::endl;
        break;
    case 2:
        break;
    default:
        std::cout << "Incorrect in";
        break;
    }
    
    return 0;
}