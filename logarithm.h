/*************************
 * Class Logarithm        *
 * TNG033: Lab 2          *
 **************************/

#pragma once

#include <iostream>

#include "expression.h"

class Logarithm : virtual public Expression {
    // ADD CODE
public:
	Logarithm();

	Logarithm(const Expression& F, double l1, double l2, int a);

	Logarithm(const Logarithm& source);

	virtual ~Logarithm();

	Logarithm& operator=(Logarithm L);

	virtual void display(std::ostream& os) const override;

	virtual double operator()(double d) const override; 
	virtual Logarithm* clone() const override;

protected:
	double c1, c2;
	int b;
	Expression* E;

};


