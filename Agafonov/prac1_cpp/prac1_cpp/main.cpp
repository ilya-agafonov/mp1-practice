#include <iostream>
#include <fstream>
#include <locale>
#include "StoreLib.h"

int main(int argc, char** argv) {
    char* infilename, * outfilename;
    int answer, flag = 0;    

    if (argc < 3) {
        std::cout << "Incorrect arguments" << std::endl;
        return 0;
    }

    infilename = argv[1];
    outfilename = argv[2];
    setlocale(LC_ALL, "Rus");

    std::ifstream infile(infilename);
    if (!infile.is_open()) {
        std::cout << "Input file not open" << std::endl;
        return 0;
    }

    std::ofstream outfile(outfilename);
    if (!outfile.is_open()) {
        std::cout << "Output file not open" << std::endl;
        return 0;
    }

    std::cout << "Что вывести? (1 - все магазины, 2 - круглосуточные магазины)" << std::endl;
    std::cin >> answer;
    switch (answer) {
    case 1:
    {
        StoreLib storelib;
        infile >> storelib;
        infile.close();

        outfile << storelib;
        outfile.close();
        std::cout << "В файл " << outfilename << " напечатаны все магазины" << std::endl;
        flag = 1;
        break;
    }
    case 2:
    {
        StoreLib storelib, lib24;
        infile >> storelib;
        infile.close();

        lib24 = storelib.get24stores();

        outfile << lib24;
        outfile.close();
        std::cout << "В файл " << outfilename << " напечатаны круглосуточные магазины" << std::endl;
        flag = 1;
        break;
    }
    default:
        std::cout << "Неверный ввод" << std::endl;
        break;
    }
    return 0;
}