#include <iostream>
#include <exception>
#include "vector.h"

TVector::TVector() {
    //std::cout << "TVector::TVector()" << std::endl;
    this->n = 0;
    this->x = nullptr;
}

TVector::TVector(int n) {
    this->n = n;
    x = new double[n];
}

TVector::TVector(const TVector& a) {
    //std::cout << "TVector::TVector(const TVector& a)" << std::endl;
    n = a.n;
    x = new double[n];
    for (int i = 0; i < n; i++) {
        x[i] = a.x[i];
    }
}

TVector::~TVector(){
    delete[] x;
}

TVector TVector:: operator+(const TVector& b) {
    //std::cout << "TVector TVector:: operator+(const TVector& b)" << std::endl;
    if (n != b.n) {
        throw "The sizes don't match";
    }
    TVector res(n);
    for (int i = 0; i < n; i++) {
        res.x[i] = x[i] + b.x[i];
    }
    return res;
}

TVector TVector::operator-(const TVector& b) {
    //std::cout << "TVector TVector::operator-(const TVector& b)" << std::endl;
    if (b.n != n) {
        throw "The sizes don't match";
    }
    TVector res(n);
    for (int i = 0; i < n; i++) {
        res.x[i] = x[i] - b.x[i];
    }
    return res;
}

double TVector::operator*(const TVector &b) {
    //std::cout << "double TVector::operator*(const TVector &b)" << std::endl;
    if (n != b.n) {
        throw "The sizes don't match";
    }
    double res = 0;
    for (int i = 0; i < n; i++) {
        res += x[i] * b.x[i];
    }
    return res;
}

TVector TVector::operator=(const TVector& b) {
    //std::cout << "TVector TVector::operator=(const TVector& b)" << std::endl;
    if (this == &b) {
        return *this;
    }
    delete[] x;
    n = b.n;
    x = new double[n];
    for (int i = 0; i < n; i++) {
        x[i] = b.x[i];
    }
    return *this;
}

std::istream& operator>>(std::istream& in, TVector& v) {
    //std::cout << "std::istream & operator>>(std::istream & in, TVector & v)" << std::endl;
    std::cout << "Input n" << std::endl;
    in >> v.n;
    std::cout << "Input x" << std::endl;
    if (v.x != nullptr) {
        delete[] v.x;
    }
    v.x = new double[v.n];
    for (int i = 0; i < v.n; i++) {
        in >> v.x[i];
    }
    return in;
}

std::ostream& operator<<(std::ostream& out,const TVector& v) {
    //std::cout << "std::ostream& operator<<(std::ostream& out, TVector& v)" << std::endl;
    out << "Vector: ";
    for (int i = 0; i < v.n; i++) {
        out << v.x[i] << " ";
    }
    return out;
}