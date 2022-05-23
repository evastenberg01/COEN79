#include <time.h>
#include <iostream>
#include <stdlib.h>
#include <stdio.h>

using namespace std;

int main()
{
	bool session = true;
//	bool ready = false;
	int tries = 0;
	int index = 0;
	int guesses[20] = {};
	char input;

	srand (time(NULL));
	
	cout << "Think of a number between 1 and 20. Press enter when you're ready." << endl;
	
	//guesses numbers until the right one is chosen
	do {
		int guess = 0;
		tries++;//number of tries it takes to guess the number
		guess = rand() % 20 + 1;//guesses random number between 1 and 20
		cout << " Is the number " << guess << " ? Y or N " << endl;
		cin >> input;
		putchar(tolower(input));

		if(input == 'y')//if correct number is guessed 
		{
			cout << "I found the number in " << tries << " steps.\n";
			session = false;
		}

		else if(input != 'n')//if incorrect number, computer keeps guessing
		{
			tries--;
			cout << "Invalid input. Please enter y or n. " << endl;
		}
	} while(session);
	return 0;
} 
