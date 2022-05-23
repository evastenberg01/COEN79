//header file

#ifndef poly_h
#define poly_h

#include <iostream>

//value semantics: copy constructor and assignment operator are valid for polynomial class

namespace coen79_lab4 
{
	class polynomial
	{
			public:

				//CONSTRUCTOR
				
				//precon: exponent <= MAXIMUM_DEGREE
				//postcon: polynomial created with all zero coefficients except for coefficient c for specified exponent. 
				//As default constructor, result is a polynomial with all zero cofficients
				polynomial(double c = 0.0, unsigned int exponent = 0);


				//HELPER MEMBER FUNCTIONS
				
				//postcon: current degree set to highest exponent with a non-zero coefficient
				void update_current_degree();
				

				//MEMBER CONSTANTS
				
				static const size_t MAXIMUM_DEGREE = 29; //size of maximum exponent permitted for polynomial
				static const size_t CAPACITY = 30; 
				

				//MODIFICATION MEMBER FUNCTION

				//precon: exponent <= MAXIMUM_DEGREE
				//postcon: sets coefficient for specified coeffieicnt
				void assign_coef(double coefficient, unsigned int exponent);

				//precon: exponent <= MAXIMUM_DEGREE
				//postcon: adds given amount to coefficient of specified exponent
				void add_to_coef(double amount, unsigned int exponent);

				//postcon: all coefficient of polynomial is set to zero
				void clear();


				//CONSTANT MEMBER FUNCTIONS

				//precon: degree() < MAXIMUM_DEGREE
				//postcon: return value is antiderivative of polynomial
				polynomial antiderivative() const;

				//postcon: returns coefficient at specified exponent of this polynomial
				double coefficient(unsigned int exponent) const;

				//postcon: returns value of definite integral computed from x0 to x1 analytically
				double definite_integral(double x0, double x1) const;

				//postcon:function returns value of largest exponent with nonzero coefficient
				//if all coefficients are zero, function returns zero
				unsigned int degree() const;

				//postcon: return value is first deriv of polynomial
				polynomial derivative() const;

				//postcon: return value is value of this polynomial with given value for variable x
				double eval(double x) const;

				//postcon: return value is true if polynomial is zero polynomial
				bool is_zero() const;

				//postcon:return value is next exponent n which is larger than e such that coefficient(n) != 0
				//if no such term exists, return value is zero
				unsigned int next_term(unsigned int e) const;

				//postcon: return value is next exponent n smaller than e such that coefficient(n) != 0
				//if there is no such term, return value is UNIT_MAX from <climits>
				unsigned int previous_term(unsigned int e) const;


				//CONSTANT OPERATORS
			
				double operator() (double x) const;

				//FRIEND FUNCTIONS
				
				//postcon: return value is a polynomial with each coeff = sum of coeff of p1 & p2
				friend polynomial operator +(const polynomial& p1, const polynomial& p2);

				//postcon: return value is a polynomial with each coeff = diff coefficients of p1 & p2
				friend polynomial operator -(const polynomial& p1, const polynomial& p2);

				//precon: p1.degree() + p2.degree() <= MAXIMUM_DEGREE
				//postcon: each term of p1 has been multiplied by each term of p2 so answer is sum of all term-by-term products
				friend polynomial operator *(const polynomial& p1, const polynomial& p2);

				//postcon: polynomial printed to outstream out
				friend std::ostream& operator << (std::ostream& out, const polynomial& p);

		private:
				double data[CAPACITY]; //hold polynomial

	};

	//postcon: return value is a polynomial with each coefficient = sum of coefficients of p1 & p2 for any given exponent
	//polynomial operator +(const polynomial& p1, const polynomial& p2);

	//postcon: return value is a polynomial with each coefficient equal to the diff of coefficients of p1 & p2 for any given exponent
	//polynomial operator -(const polynomial& p1, const polynomial& p2);

	//precon: p1.degree() + p2.degree() <= MAXIMUM_DEGREE
	//postcon: each term of p1 has been multiplied by each term p2, and answer is sum of all there term-by-term products
	//polynomial operator *(const polynomial& p1, const polynomial& p2);

	//postcon: polynomial printed to ostream out, returned to calling functions. the format is:
	//1)one space between operator and numbers, 2) constant coefficient printed by itself, 3) first coefficient followed by x, 4) highest degree
	//coefficient has a sign but following value is all seperated by appropriate operator and then print unsigned, 5) manipulate any settings of
	//outstream inside this should restore polynomial to what it was at start of function before starting
	//std::ostream& operator << (std::ostream& out, const polynomial& p);

}

#endif
