#include <cctype>
#include <iostream>
#include <cstdlib>
#include "bag_bst.h"

using namespace std;
using namespace coen79_lab9;

void display_bags(const bag<double>& b1, const bag<double>& b2);
bag<double> copybag(bag<double> b2);

int main() {
	bag<double> b1, b2;
	
	b1.insert(1);
	b1.insert(3);
	b1.insert(5);
	b1.insert(7);
	b1.insert(9);
	b2.insert(2);
	b2.insert(4);
	b2.insert(6);
	b2.insert(8);
	b2.insert(0);

	display_bags(b1, b2);
	cout << "\n" << endl;

	b1.erase_one(1);
	b1.erase_one(3);
	b1.erase_one(5);
	b1.erase_one(7);
	b1.erase_one(9);

	display_bags(b1, b2);
	cout << "\n" << endl;

	b1 = copybag(b2);

	display_bags(b1, b2);
	cout << "\n" << endl;

	b1.insert(2);
	b1.insert(2);
	b1.insert(2);
	b1.erase(2);
	b1.erase(8);
	
	display_bags(b1, b2);
	cout << "\n" << endl;
}

void display_bags(const bag<double>& b1, const bag<double>& b2)
{
	int i;
	for(i = 0; i < 10; i++)
	{
		cout << i << " in b1? " << b1.count(i);
		cout << "            " << i << " in b2? " << b2.count(i) << endl;
	}
}

bag<double> copybag(bag<double> b) {
	return b;
}
