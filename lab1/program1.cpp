#include <iostream>

using namespace std;

int main(void)
{
	int i, size;
	int alphanumeric = 0; //counts alphanumeric characters
	int nonalphanumeric = 0; //counts nonalphanumeric characters
	int length; //length of users string
	string text; //stores inputted text in an array
	
	cout << "Enter text:\n";
	getline(cin, text); //places inputted text
	size = text.size();

	//loop to count lowercase letters, uppercase letters and non alphanumeric characters
	for(i = 0; i < size; i++)
	{
		if(isalnum(text[i])) //lowercase
			alphanumeric++;
		else 
			nonalphanumeric++;
	}
	//subtracts for spaces that were counted in previous for loop
	for(i=0;i<size;i++)
	{
		if(text[i] == ' ')
			nonalphanumeric--;
	}
	//prints the number of alpha and nonalphanumeric characters
	cout << "Number of alphanumeric characters: " << alphanumeric << endl;
	cout << "Number of nonalphanumeric characters: " << nonalphanumeric << endl;

	return 0;
}
