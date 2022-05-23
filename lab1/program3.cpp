#include <iostream>
#include <string>
#include <stdio.h>
#include <ctype.h>
#include <fstream>

using namespace std;

//function to read in text file, erase all non-alphanumeric characters and convert  to uppercase
int main(int argc, char* argv[])
{
	int i;
	ifstream file; //stream class to read from files
	string s = "";
	char ch;
	
	file.open(argv[1]); //opens the file
	
	while(file >> s) //until text is no longer in file
	{
		if(s.length() >= 10) //checks if longer than 10 characters
		{
			for(i = 0; i< s.length(); i++)
			{
				ch = s[i];
				if(!isalpha(ch)) //checks if c is not an alphabetic character
				{
					s.erase(i,1); //erases non-alphabetic characters
					i--;
				}
				else
				{
					putchar(toupper(ch));//converts to uppercase
				}
			
			}
			cout << " \n";
		}
	}
	file.close();
	return 0;
}
