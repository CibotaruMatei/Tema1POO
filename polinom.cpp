#include <iostream>
#include <fstream>
#include <cmath>
#include "polinom.h"

Polinom::Polinom() {
    coef = new double[1];
    coef[0] = 0;
    grad = -1;
}

Polinom::Polinom(int grad) {
    if (grad == -1) {
        coef = new double[1];
        coef[0] = 0;
        this->grad = -1;
    }
    else {
        this->grad = grad;
        coef = new double[grad + 1];
        for (int i = 0; i <= grad; i++)
            coef[i] = 0;
    }
}

Polinom::Polinom(const double * v, int size, bool backwards) {
    if (size == 0) {
        coef = new double[1];
        coef[0] = 0;
        grad = -1;
    }
    else {
        coef = new double[size];
        grad = size - 1;
        if (backwards) {
            for (int i = size - 1; i >= 0; i--) {
                coef[i] = v[i];
            }
        }
        else {
            for (int i = 0; i < size; i++) {
                coef[i] = v[i];
            }
        }
    }
}

Polinom::Polinom(const Polinom &p) {
    if (p.grad == -1) {
        coef = new double[1];
        coef[0] = 0;
        grad = -1;
    }
    else {
        coef = new double[p.grad + 1];

        grad = p.grad;
        for (int i = 0; i <= grad; i++) {
            coef[i] = p.coef[i];
        }
    }
}

Polinom::~Polinom() {
    delete[] coef;
}

double Polinom::getValueAt(double x) const {
    double res = 0;
    for (int i = 0; i <= grad; i++) {
        res += coef[i]*pow(x, i);
    }
    return res;
}

Polinom Polinom::operator+(const Polinom& p) {
    const Polinom& bigpol = (grad > p.grad ? (*this) : p);
    const Polinom& smallpol = (grad > p.grad ? p : (*this));
    if (smallpol.grad == -1) return bigpol;

    Polinom newpol(bigpol);
    
    for (int i = 0; i <= smallpol.grad; i++)
        newpol.coef[i] += smallpol.coef[i];
    
    while (newpol.coef[newpol.grad] == 0) {
        newpol.grad--;
    }

    return newpol;
}

Polinom operator-(const Polinom& p) {
    Polinom newp(p.grad);
    for (int i = 0; i <= p.grad; i++)
        newp.coef[i] = -p.coef[i];
    return newp;
}

Polinom Polinom::operator-(const Polinom& p) {
    Polinom nullpol; 
    if ((*this) == p) {
        return nullpol;
    }
    if ((*this) == nullpol) {
        return -p;
    }
    if (p == nullpol) {
        return (*this);
    }
    return (*this) + (-p);
}

Polinom Polinom::operator*(const Polinom& p) {
    if (grad == -1) return (*this);
    if (p.grad == -1) return p;
    Polinom newp(grad + p.grad);
    for (int i = 0; i <= grad; i++) {
        for (int j = 0; j <= p.grad; j++) {
            newp.coef[i + j] += coef[i] * p.coef[j];
        }
    }
    return newp;
}

Polinom& Polinom::operator=(const Polinom& p) {
    if (this != &p) {
        grad = p.grad;
        delete[] coef;
        if (grad == -1) {
            coef = new double[1];
            coef[0] = 0;
        }
        else {
            coef = new double[grad + 1];
            for (int i = 0; i <= grad; i++) {
                coef[i] = p.coef[i];
            }
        }
    }
    return *this;
}

std::ostream& operator<<(std::ostream& os, Polinom& p) {
    if (p.grad == -1) {
        os << 0 << " ";
    }
    else {
        os << p.coef[0] << " ";
        for (int i = 1; i <= p.grad; i++) {
            if (p.coef[i] < 0) {
                os << "- " << -p.coef[i] << "*x^" << i << " ";
            }
            else if (p.coef[i] > 0) {
                os << "+ " << p.coef[i] << "*x^" << i << " ";
            }
        }
    }
    return os;
}

std::istream& operator>>(std::istream& is, Polinom& p) {
    delete[] p.coef;
    is >> p.grad;
    if (p.grad == -1) {
        p.coef = new double[1];
        p.coef[0] = 0;
    }
    else {
        p.coef = new double[p.grad + 1];
        for (int i = 0; i <= p.grad; i++) {
            is >> p.coef[i];
        }
    }
    return is;
}

bool operator==(const Polinom& p1, const Polinom& p2) {
    if (p1.grad == p2.grad) {
        for (int i = 0; i <= p1.grad; i++)
            if (p1.coef[i] == p1.coef[i])
                return false;
        return true;
    }
    return false;
}

Polinom* read_n(std::istream& is, int count) {
    Polinom* v = new Polinom[count];
    for (int i = 0; i < count; i++) {
        is >> v[i];
    }
    return v;
}

void show_n(std::ostream& os, Polinom* v, int count) {
    for (int i = 0; i < count; i++) {
        os << "v[" << i << "] = " << v[i] << std::endl;
    }
}

int main()
{
    //Exemple de polinoame si operatii cu ele
    Polinom* v;
    std::fstream f("input.txt", std::ios::in);
    v = read_n(f, 4);
    show_n(std::cout, v, 4);

    std::cout << std::endl;

    Polinom p = v[0] * v[1];
    std::cout << "v[0] * v[1] = " << p << std::endl << std::endl;

    p = v[3] - v[2];
    std::cout << "v[3] - v[2] = " << p << std::endl << std::endl;

    p = v[2] - v[3];
    std::cout << "v[2] - v[3] = " << p << std::endl << std::endl;

    p = v[3] - v[3];
    std::cout << "v[3] - v[3] = " << p << std::endl << std::endl;

    p = v[2] * v[3];
    std::cout << "v[2] * v[3] = " << p << std::endl << std::endl;

    return 0;
}