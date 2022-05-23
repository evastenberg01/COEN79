//implementation file

#include "poly.h"
#include <fstream>
#include <cassert>
#include <iostream>
#include <climits>
#include <cmath>
#include "polygif.cpp"

using namespace std;

namespace coen79_lab4
{

	//constructor
	polynomial::polynomial(double c, unsigned int exponent)
	{
		assert(exponent <= polynomial::MAXIMUM_DEGREE); //make sure exponent is not at max

		for (int i = 0; i < CAPACITY; ++i)
		{
			polynomial::data[i] = 0; //initialize array to 0
		}

		data[exponent] = c;
	}


	void polynomial::assign_coef(double coefficient, unsigned int exponent)
	{
		assert(exponent <= polynomial::MAXIMUM_DEGREE); //ensures exponent is not at max
		data[exponent] = coefficient; //assign passed coef at right exponent
	}


	void polynomial::add_to_coef(double amount, unsigned int exponent)
	{
		assert(exponent <= polynomial::MAXIMUM_DEGREE); //ensures not have yet reached max degree
		data[exponent] += amount; //changes coeff
	}


	void polynomial::clear()
	{
		polynomial(0.0, 0.0); //calls constructor to initialize array to be 0's
	}


	unsigned int polynomial::degree() const
	{
		for (int i = CAPACITY - 1; i >= 0; --i) //goes through polynomial
		{

			if (data[i] != 0) //does coef exist?
			{
				return i; //returns exponent
			}

		}

		return 0; //highest degree in polynomial
	}


	double polynomial::coefficient(unsigned int exponent) const
	{

		if (exponent > polynomial::MAXIMUM_DEGREE) //if exponent past number of max degree
		{
			return 0; //coef doesn't exist
		}

		else //exponent exists in scope
		{
			return data[exponent]; //return coeff val at exponent
		}

	}


	double polynomial::eval(double x) const 
	{

		for (int i = 0; i < polynomial::CAPACITY; ++i) //goes through polynomial
		{
			if (data[i] == x) //MATCH
			{
				return data[i]; //returns exponent value
			}
		}

		return 0.0; //doesn't exist
	}


	polynomial polynomial::antiderivative() const
	{
		assert( degree() < polynomial::MAXIMUM_DEGREE); //degree in polynomial HAS to be less than degree supported

		polynomial x(0.0, 0.0); //will hold polynomial antiderivative

		for (int i = 0; i < polynomial::MAXIMUM_DEGREE; ++i) //go through current polynomial
		{
			x.data[i+1] = (data[i]/i+1); //shifts everything right and solves for antideriv

		}

		x.data[0] = 0; //stays 0

		return x; //return antideriv
	}


	double polynomial::definite_integral(double x0, double x1) const
	{
		double top = 0.0; //upper bound
		double bottom = 0.0; //lower bound

		polynomial y; //holds antideriv
		y = antiderivative(); //solve for antideriv

		for (int i = 0; i < polynomial::MAXIMUM_DEGREE; ++i) //go through polynomial
		{
			top += (y.data[i] * pow(x0, i) ); //sums up all upper bounds
			bottom += (y.data[i] * pow(x1, i) ); //sums up all lower bounds
		}

		return top - bottom; //return difference btween bounds
	}


	polynomial polynomial::derivative() const
	{
		polynomial z; //will hold derivative

		for (int i = 1; i < polynomial::MAXIMUM_DEGREE; ++i) //iterate through polynomial
		{
			z.data[i-1] = (data[i] * i); //solve for derivative and put in poly z
		}

		return z; //return derivative

	}


	bool polynomial::is_zero() const
	{
		for (int i = 0; i < polynomial::MAXIMUM_DEGREE; ++i) //checks each position
		{

			if (data[i] != 0)
			{
				return false; //coefficient exists that doesn't = 0
			}

		}

		return true; //each coefficient is 0
	}


	unsigned int polynomial::next_term(unsigned int e) const
	{
		for (int i = e + 1; e < polynomial::CAPACITY; ++i) //searches polynomial
		{
			if (data[i] != 0) //exponent larger than e
			{
				return i; //returns coefficient
			}
		}

		return 0; //no such term exists
	}


	unsigned int polynomial::previous_term(unsigned int e) const
	{
		for (int i = e - 1; i >= 0; --i) //searches polynomial
		{
			if (data[i] != 0) //exponent smaller than e
			{
				return i; //returns prev term that is not zero
			}
		}

		return 0; //doesn't exist
	}


	double polynomial::operator()(double x) const
	{
		return eval(x); //same as eval member function
	}


	polynomial operator+(const polynomial& p1, const polynomial& p2)
	{
		polynomial x; //holds result of operation overload

		for (int i = 0; i < polynomial::CAPACITY; ++i)
		{
			x.data[i] = p1.data[i] + p2.data[i]; //adds coeff at same position and puts sum in x
		}

		return x;
	}


	polynomial operator-(const polynomial& p1, const polynomial& p2)
	{
		polynomial x; //holds result of operation overload

		for (int i = 0; i < polynomial::CAPACITY; ++i)
		{
			x.data[i] = abs(p1.data[i] - p2.data[i]); //subtracts each coeff and puts that value in same position in x
		}

		return x;
	}

	polynomial operator*(const polynomial& p1, const polynomial& p2)
	{
		assert(p1.degree() + p2.degree() <= polynomial:: MAXIMUM_DEGREE); //can this operation be supported?

		polynomial x; //holds result

		for (int i = 0; i < polynomial::CAPACITY; ++i)
		{
			for (int j = 0; j < polynomial::CAPACITY; ++i)
			{
				x.data[i+j] += (p1.data[i] * p2.data[j]); //perform multiplication between obj and put value in x
			}
		}
		
		return x;
	}


	std::ostream& operator <<(ostream& out, const polynomial& p)
	{

		for (int i = p.degree(); i>= 0; --i) //go through polynomial
		{
			if (i > 1) //if x with exponent exists
			{
				out << p.data[i] + 'x' + '^' + i + ' '; //output with degree
			}

			else if (i == 1) //if x exists
			{
				out << p.data[i] + 'x' + ' '; //output with x
			}

			else //constant
			{
				out << p.data[i]; 
			}
		}

		return out; //need to return because of ostream
	}



} 
//namespace
