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
    string me_first("Demo"), me_last("Program");
    string you_first, you_last, you;

    cout << "What is your first name? ";
    cin >> you_first;
	cout << you_first;
    match("first name", me_first, you_first);
    cout << "What is your last name? ";
    cin >> you_last;
    match("last name", me_last, you_last);

    you = you_first + BLANK + you_last;
    cout << "I am happy to meet you, " << you << "." << endl;
    return EXIT_SUCCESS;
}

void match(const string& variety, const string& mine, const string& yours)
{
    if (mine == yours)
        cout << "That is the same as my " << variety << "!" << endl;
    else
        cout << "My " << variety << " is " << mine << "." << endl;
}
