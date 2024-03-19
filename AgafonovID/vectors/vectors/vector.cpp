#include <iostream>
#include <exception>
#include "vector.h"

TVector::TVector() {
    std::cout << "TVector::TVector()" << std::endl;
    this->n = 0;
    this->x = nullptr;
}

TVector::TVector(int n) {
    std::cout << "TVector::TVector(int n)" << std::endl;
    this->n = n;
    this->x = new double[this->n];
}

TVector::TVector(const TVector& a) {
    std::cout << "TVector::TVector(const TVector& a)" << std::endl;
    this->n = a.n;
    this->x = new double[this->n];
    for (int i = 0; i < this->n; i++) {
        this->x[i] = a.x[i];
    }
}

TVector::~TVector(){
    std::cout << "TVector::~TVector()" << std::endl;
    delete[] this->x;
}

TVector TVector:: operator+(const TVector& b) {
    std::cout << "TVector TVector:: operator+(const TVector& b)" << std::endl;
    if (this->n != b.n) {
        throw std::exception("Different len");
    }
    TVector res(this->n);
    for (int i = 0; i < this->n; i++) {
        res.x[i] = this->x[i] + b.x[i];
    }
    return res;
}

TVector TVector::operator-(const TVector& b) {
    std::cout << "TVector TVector::operator-(const TVector& b)" << std::endl;
    if (this->n != b.n) {
        throw std::exception("Different len");
    }
    TVector res(this->n);
    for (int i = 0; i < this->n; i++) {
        res.x[i] = this->x[i] - b.x[i];
    }
    return res;
}

double TVector::operator*(const TVector &b) {
    std::cout << "double TVector::operator*(const TVector &b)" << std::endl;
    if (this->n != b.n) {
        throw std::exception("Different len");
    }
    double res = 0;
    for (int i = 0; i < b.n; i++) {
        res += this->x[i] * b.x[i];
    }
    return res;
}

const TVector& TVector::operator=(const TVector& b) {
    if (this != &b) { 
        delete[] x;   
        n = b.n;      
        x = new double[n]; 
        for (int i = 0; i < n; i++) {
            x[i] = b.x[i]; 
        }
    }
    return *this;
}

std::istream& operator>>(std::istream& in, TVector& v) {
    std::cout << "std::istream& operator>>(std::istream& in, TVector& v)" << std::endl;
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
    std::cout << "std::ostream& operator<<(std::ostream& out,const TVector& v)" << std::endl;
    out << "Vector: ";
    for (int i = 0; i < v.n; i++) {
        out << v.x[i] << " ";
    }
    return out;
}