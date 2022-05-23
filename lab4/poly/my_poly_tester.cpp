#include <iostream>
#include "poly.h"

using namespace std;
using coen79_lab4::polynomial;

const unsigned int MANY = 3; //number of polynomials allowed in test program

void view(const polynomial& test);
void view_all(const polynomial a[]);
void test_add(polynomial& test);
void test_assign(polynomial& test);
void test_clear(polynomial& test);
//void test_gif(const polynomial& test);
void test_eval(const polynomial& test);
void test_np(const polynomial& test);

void view(const polynomial& test)
{
	cout << test << "(degree is " << test.degree() << ")" << endl;
}

void test_assign(polynomial& test)
{
	double coefficient;
	unsigned int exponent;
	test.assign_coef(4, 3);
	test.assign_coef(6, 2);
	test.assign_coef(8, 1);
	test.assign_coef(1, 1);
	view(test);
}

void test_add(polynomial& test)
{
	double coefficient;
	unsigned int exponent;
	test.add_to_coef(2, 1);
	view(test);
}

/*void test_gif(const polynomial& test)
{
	char file_name[20];
	double high_x, low_x, high_y, low_y;
	make_gif(test, polyfile, 1, 13, 2, 19);
	cout << "The file has been written" << endl;
}
*/

void test_eval(const polynomial& test)
{
	double x_value;
	view(test);
	cout << "The evaluation returned is " << test(10) << endl;
}

void view_all(const polynomial p[])
{
	size_t i;
	cout << endl;
	for(i = 0; i < MANY; ++i)
	{
		cout << char(i + 'A') << ": ";
		view(p[i]);
	}
}

void test_clear(polynomial& test)
{
	test.clear( );
	cout << "After clearing: ";
	view(test);
}

void test_np(const polynomial& test)
{
	unsigned int exponent;
	cout << "next term = " << test.next_term(3) << endl;
	cout << "previous term = " << test.previous_term(2) << endl;
}

int main()
{
	polynomial p[MANY];
	size_t current_index = 0;
	
	test_assign(p[current_index]);
	test_add(p[current_index]);
	view(p[current_index]);
	test_eval(p[current_index]);
	//test_gif(p[current_index]);
	test_np(p[current_index]);
	test_clear(p[current_index]);

	return 0;
}
