/*************************
 * Class Expression       *
 * TNG033: Lab 2          *
 **************************/

#pragma once

#include <iostream>

constexpr double Epsilon = 1.0e-5;

class Expression 
{
public:
    //default constructor
    Expression() {
        ++count_expressions;
    }

    // Destructor
    virtual ~Expression() {
        --count_expressions;
    }

    // ADD OTHER MEMBER FUNCTIONS
    bool isRoot(double x) const; //test if a given value x is the root of the function
    Expression& operator=(Expression& E) = delete;

    //Pure virtual functions : 
    virtual double operator()(double d) const = 0; // makes it abstract
    virtual Expression* clone() const = 0;
    // Return number of existing instances of class Expression
    // Used only for debug purposes
    static std::size_t get_count_expressions();

protected:
    // Default constructor
    //Expression() {
     //   ++count_expressions;
    //}
    friend std::ostream& operator<<(std::ostream& os, const Expression& E)
    {
        E.display(os);
        E.display(std::cout);
        return os;
        
    }
    virtual void display(std::ostream& os) const = 0;
    // Copy constructor
    Expression(const Expression&) {
        ++count_expressions;
    }

    // Total number of existing expressions -- to help to detect bugs in the code
    static std::size_t count_expressions;
};
