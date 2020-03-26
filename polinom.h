#pragma once
#ifndef POLINOM_H_INCLUDED
#define POLINOM_H_INCLUDED
#include <iostream>

class Polinom {
public:
	Polinom();

	Polinom(int);

	Polinom(const double *, int, bool=false);

	Polinom(const Polinom&);

	~Polinom();

	double getValueAt(double) const;

	Polinom operator+(const Polinom&);

	friend Polinom operator-(const Polinom&);

	Polinom operator-(const Polinom&);

	Polinom operator*(const Polinom&);

	Polinom& operator=(const Polinom&);

	friend std::ostream& operator<<(std::ostream&, Polinom&);

	friend std::istream& operator>>(std::istream&, Polinom&);

	friend bool operator==(const Polinom&, const Polinom&);

	friend Polinom* read_n(std::istream&, int);

	friend void show_n(std::ostream&, Polinom*, int);
private:
	double * coef;
	int grad;
};

#endif
