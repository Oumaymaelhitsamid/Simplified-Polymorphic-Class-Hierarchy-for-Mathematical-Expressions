/*********************************************************
 * Class Polynomial member functions implementation       *
 * TNG033: Lab 2                                          *
 **********************************************************/

#include "polynomial.h"
#include <cmath>
#include <iomanip>
#include <vector>

// ADD implementation of the member functions for class Polynomial

//Default constructor
Polynomial::Polynomial(double d) : degree{ 0 }
{
	coefficients.push_back(d);
}
Polynomial::Polynomial(std::vector<double> v) : degree{(int) v.size()-1}
{
	coefficients = v;
}
Polynomial::Polynomial(const Polynomial& source)
{  
	coefficients = source.coefficients;
	degree = source.degree;
}


Polynomial& Polynomial::operator=(Polynomial P)
{

	//ADD CODE
	//std::swap(degree, P.degree);
	degree = P.degree;
	coefficients = P.coefficients;

	//swap coefficients

	return *this;
}

//Addition operator
Polynomial& Polynomial::operator+=(const Polynomial& P)
{
	//ADD CODE
	 

	if (this->degree <= P.degree) {

		

		for (int i = 0; i <= this->degree; i++) {
			this->coefficients[i] += P.coefficients[i];
		}
		for (int i = this->degree + 1; i <= P.degree; i++) {
			this->coefficients.push_back( P.coefficients[i]);
		}
		degree = P.degree;
	}
	else {
		for (int i = 0; i <= P.degree; i++) {

			this->coefficients[i] += P.coefficients[i];
		}
	}
	
	return *this;
	
}

//operator()
double Polynomial::operator()(double d) const
{
	double sum = 0;

	for (int i = 0; i <= degree; i++) {
		sum += coefficients[i] * pow(d, i);
	}

	return sum; //to be deleted  ?
}

//subscript operator
double& Polynomial::operator[](int i)
{
	double d = 0.0; //no such coefficient exists
	if (i <= degree) {
		return coefficients[i];
	}

	
	std::cout << "No such coefficient exists" << std::endl;
	//return d; //to be deleted?
}

 double Polynomial::operator[](int i) const
{
	double d = 0.0; //no such coefficient exists
	if (i <= degree) {
		return coefficients[i];
	}

	
	std::cout << "No such coefficient exists" << std::endl;
	//return d; //to be deleted? 
}

//clone
Polynomial* Polynomial::clone() const
{
	//Polynomial* P{*this};
	return new Polynomial{ *this }; //to be deleted ?
}

Polynomial operator+(Polynomial lhs, const Polynomial& rhs)
{
	//std::cout << "Test operator + " << std::endl;
	Polynomial temp{ lhs };
	temp.operator+=(rhs);

	return temp;
}

void Polynomial::display(std::ostream& os) const
{
	os << std::fixed << std::setprecision(2) << coefficients[0];
	for (int i = 1; i <= degree; i++) {
		
			
			
			if (coefficients[i] < 0) {
				os << std::fixed << std::setprecision(2) << " - " << abs(coefficients[i]) << " * X^" << i;
			}
			else {
				os << std::fixed << std::setprecision(2) << " + " << coefficients[i] << " * X^" << i;
			}
			
		
		

	}
}