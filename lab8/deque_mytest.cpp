#include <iostream>
#include "deque.h"

using namespace coen79_lab8;
using std::endl;
using std::cout;

int main(int argc, const char * argv[]) {

	int test = 0;
	
	//testing constructor
	cout << "testing constructor" << endl;
	coen79_lab8::deque<int>	first;

	//test push_back and back()
	cout << "testing push_back() and back()" << endl;
	for(int i = 0; i < 10; ++i)
	{
		first.push_back(i);
		cout << first.back() << " ";
	}
	
	//test iterator
	cout << "\ntesting iterator" << endl;
	for (deque<int>::iterator it = first.begin(); it != first.end(); ++it)
		cout << *it << " ";

	//test pop_front
	cout << "\ntesting pop_front" << endl;
	for(int i = 0; i < 100; ++i)
		first.pop_front();
	cout << "Front is: " << first.front() << endl;
	cout << "back is: " << first.back() << endl;

	//testing pop_back()
	cout << "testing pop_back() " << endl;
	for(int i = 0; i < 10; ++i)
		first.pop_back();
	cout << "front is: " << first.front();
	cout << "back is: " << first.back();

	//test iterator again
	cout << "testing iterator part 2" << endl;
	for(deque<int>::iterator it = first.begin(); it != first.end(); ++it)
		cout << *it << " ";

	//testing assignement operator
	cout << "testing assignment operator" << endl;
	coen79_lab8::deque<int> second;
	second.push_front(20);
	second.push_back(30);
	second.push_back(40);
	second.push_front(10);
	second.push_back(50);
	second.push_back(60);

	coen79_lab8::deque<int> third;
	third = second;

	for(deque<int>::iterator it = third.begin(); it != third.end(); ++it)
		cout << *it << " ";

	//testing copy constructor
	cout << "testing copy constructor" << endl;
	coen79_lab8::deque<int> fourth(third);
	for(deque<int>::iterator it = fourth.begin(); it != fourth.end(); ++it)
		cout << *it << " ";

	//final iterator test
	cout << "final iterator test" << endl;
	deque<int>::iterator it_start = fourth.begin();
	deque<int>::iterator it_end = fourth.end();
	deque<int>::iterator it2 = it_start;

	while(it2 != it_end)
	{
		*it2 = 950;
		++it2;
	}
	it2 = it_start;
	while(it2 != it_end)
	{
		cout << *it2 << " ";
		it2++;
	}
	cout << "success" << endl;
}
