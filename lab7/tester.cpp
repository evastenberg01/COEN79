#include "database.h"

using namespace coen79_lab7;
using std::cout;
using std::cin;
using std::endl;

int main(int argc, const char * argv[]) {
	database myDB1;
	myDB1.insert_company("Apple");
	myDB1.insert_company("Amazon");
	myDB1.insert_company("Nike");

	myDB1.print_companies();

	myDB1.insert_item("Apple", "iPhone 3", 100.0);
	myDB1.insert_item("Apple", "iPhone 4", 200.0);
	cout << "Printing myDB1: " << endl;
	myDB1.print_items_by_company("Apple");

	cout << "Inserting new company names: " << endl;
	myDB1.insert_company("Microsoft");
	myDB1.insert_company("Google");

	cout << "Inserting more product names: " << endl;
	myDB1.insert_item("Microsoft", "Mic1", 0.0);
	myDB1.insert_item("Microsoft", "Mic2", 2.0);
	myDB1.insert_item("Google", "Gmail", 1000.0);
	myDB1.insert_item("Nike", "Pros", 10.0);
	myDB1.print_items_by_company("Microsoft");
	myDB1.print_items_by_company("Google");
	myDB1.print_items_by_company("Nike");

	cout << "Creating myDB2 " << endl;
	database *myDB2 = new database();

	myDB2->insert_company("Target");
	myDB2->insert_item("Target", "Shirts", 20.0);
	myDB2->insert_item("Target", "Pants", 30.0);
	myDB2->insert_item("Target", "Hats", 10.0);
	cout << "Printing Target:" << endl;
	myDB2->print_items_by_company("Target");

	database *myDB3 = new database();
	cout << "assigning myDB2 to myDB3" << endl;
	*myDB3 = *myDB2;
	myDB3->print_items_by_company("Target");

	delete myDB2;
	delete myDB3;

	return 0;
}

