#include <iostream>
#include <cstdlib>     
#include "mystring.h"   

using std::cin;
using std::cout;
using std::endl;
using namespace coen79_lab5;

void match(const string& variety, const string& mine, const string& yours);

int main( )
{
		const string BLANK(" ");
    	string me_first("Cat"), me_last("Dog");
    	char test_one_first[15] = "Cat";
		char test_one_last[15] = "Dog";
		match("first name", me_first, test_one_first);
		match("last name", me_last, test_one_last);
		char test_two_first[15] = "CAT";
		char test_two_last[15] = "cat";
		match("first name", me_first, test_two_first);
		match("last name", me_last, test_two_last);
		char test_three_first[15] = "cat";
		char test_three_last[15] = "DoG";
		match("first name", me_first, test_three_first);
		match("last name", me_last, test_three_last);


    	/*cout << "What is your first name? ";
    	cin >> you_first;
    	match("first name", me_first, you_first);
    	cout << "What is your last name? ";
    	cin >> you_last;
    	match("last name", me_last, you_last);

    	you = you_first + BLANK + you_last;*/
    	
		 return EXIT_SUCCESS;
}

void match(const string& variety, const string& mine, const string& yours)
{
    if (mine == yours)
        cout << "same " << variety << endl;
    else
        cout << "different " << variety << endl;
}
