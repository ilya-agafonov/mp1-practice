#include <iostream>

struct TVector {
    int n;
    double* x;
    
    TVector(int n);
    TVector(const TVector&);
    ~TVector();
    TVector operator+(const TVector&);
    TVector operator - (const TVector&);
    double operator *(const TVector&);
    //оператор присваивания
};

TVector::TVector(int n) {
    this->n = n;
    x = new double[n];
}

TVector::TVector(const TVector& a) {
    n = a.n;
    x = new double[n];
    for (int i = 0; i < n; i++) {
        x[i] = a.x[i];
    }
}