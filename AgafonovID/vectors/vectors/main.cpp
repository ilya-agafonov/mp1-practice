#include "vector.h"


int main(int argc, char** argv) {
    char* infile, * outfile;
    TVector v1, v2, sum, dif;
    double p; 

    infile = argv[1];
    outfile = argv[2];
    std::cout << "infile name: " << infile << std::endl;
    std::cout << "outfile name: " << outfile << std::endl;

    std::ifstream A;
    std::ofstream B;

    A.open(infile);
    if (!A.is_open()) {
        std::cout << "file A not open" << std::endl;
    }
    A >> v1 >> v2;
    A.close();
    try {
        sum = v1 + v2;
        dif = v1 - v2;
        p = v1 * v2;
    }
    catch (const std::exception& ex) {
        std::cout << ex.what() << std::endl;
        exit(1);
    }
    B.open(outfile);
    if (!B.is_open()) {
        std::cout << "file B not open" << std::endl;
    }

    B << v1<<std::endl;
    B << v2 << std::endl;
    B <<"Sum" << sum << std::endl;
    B << "Dif " << dif << std::endl;
    B << "scalar product = " << p << std::endl;
    B.close();

    return 0;
}