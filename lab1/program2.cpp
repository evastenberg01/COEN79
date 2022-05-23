#include <iostream>
#include <stdio.h>
#include <iomanip>
#include <string>

using namespace std;

int main()
{
	string str;
	string rev;//reverse string
	cout << "Input String of 10 digits (no spaces)";
	getline(cin,str);//recieves users input
	rev = str;
	
	if(str.length() != 10)//checks that string length is 10
	{
		cout << "Incorrect string length.\n";//quits if under or over 10 numbers
		return 0;
	}
	
	for(int i = 0; i < rev.length()/2; i++)//traverses string
	{
		swap(rev[i], rev[rev.length() - i - 1]);//reverses numbers
	}
	
	for(int i = 0; i < 5; i++)//prints in specified pattern
	{
	//	for( int j = 0; j < 1; j++)
		
		cout << "";
		cout << std::setw(i+10);
		cout << str << setw(20)  << rev << "\n";
	}
	return 0;
} 
