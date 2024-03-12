#include "vector.h"

int main() {
    TVector v1, v2;
    std::cin >> v1 >> v2;
    TVector sum = v1 + v2;
    TVector dif = v1 - v2;
    double p = v1 * v2;
    std::cout << v1 << std::endl;
    std::cout << v2 << std::endl;
    std::cout <<"Sum = " << sum << std::endl;
    std::cout <<"dif = " << dif << std::endl;
    std::cout <<"scalar product = " << p << std::endl;

    return 0;
}