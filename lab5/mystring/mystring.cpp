#include "mystring.h"
#include <cctype>
#include <cassert>
#include <string.h>
#include <iostream>

using namespace coen79_lab5;
using std::cout;
using std::cin;
using std::endl;

namespace coen79_lab5{
	
	//CONSTRUCTOR, COPY CONSTRUCTOR, and DESTRUCTOR
	string::string(const char str[]) 
	{
		current_length = strlen(str);
		allocated = strlen(str) + 1;
		characters = new char[allocated];
		strncpy(characters, str, allocated);
	}

	string::string(char c) 
	{
		current_length = 1;
		allocated = current_length + 1;
		characters = new char[allocated];
		characters[0] = c;
		characters[1] = '\0';
	}

	string::string(const string& source)
	{
		characters = new char[source.current_length];
		strncpy(characters, source.characters, source.current_length);
		current_length = source.current_length;
		allocated = source.allocated;
	}

	string::~string()
	{
		delete [] characters;
		current_length = 0;
		allocated = 0;
	}

	//MODIFICATION MEMBER FUNCTIONS
	void string::operator +=(const string& addend)
	{
		size_t addLength = addend.current_length;
		size_t finalLength = current_length + addLength;
		allocated = finalLength + 1;
		reserve(allocated);
		strncat(characters, addend.characters, addLength);
		current_length = finalLength;
		return;
	}

	void string::operator +=(const char addend[])
	{
		size_t addLength = strlen(addend);
		size_t finalLength = current_length + addLength;
		allocated = finalLength + 1;
		reserve(allocated);
		strncat(characters, addend, addLength);
		current_length = finalLength;
		return;
	}

	void string::operator +=(char addend)
	{
		size_t finalLength = current_length + 1;
		allocated = finalLength + 1;
		reserve(allocated);
		characters[current_length] = addend;
		current_length = finalLength;
		return;
	}

	void string::reserve(size_t n) //requests a change in capacity
	{
		char* new_characters = new char[n];
		if(characters != NULL) //traverses the array and copies characters to new characters
		{
			strncpy(new_characters, characters, current_length);
			delete [] characters; //deletes characters to avoid leaked memory
		}
		characters = new_characters;
		return;
	}

	string& string::operator =(const string& source)
	{
		this->dlt(0, current_length);
		if(current_length != source.current_length) //checks if length is different from source length
		{
			allocated = source.allocated; //copies source.allocated to previous allocated
			reserve(allocated); 
		}
		strncpy(characters, source.characters, source.current_length);
		current_length = source.current_length;
		return *this;
	}

	void string::insert(const string& source, unsigned int position)
	{
		assert(position <= length());
		char *temp1 = new char[current_length + source.current_length + 1];
		if(position > 0) //copies position into temp1
		{
			strncpy(temp1, characters, position);
		}
		char *temp2 = new char[allocated - position];
		for(int i = position, j = 0; i <= current_length; i++, j++){ //copies array
			temp2[j] = characters[i];
		}
		delete[] characters;
		strncat(temp1, source.characters, source.current_length);
		strncat(temp1, temp2, strlen(temp2));
		characters = temp1;
		current_length += source.current_length;
		allocated = current_length + 1;
		return;
	}

	void string::dlt(unsigned int position, unsigned int num)
	{
		assert((position + num) <= length());
		for(int i = position; i < length(); i++) //deletes num in position and decreases the rest of the array by 1 position
		{
			characters[i] = characters[i + num];
		}
		current_length -= num;
		return;
	}


	void string::replace(char c, unsigned int position)
	{
		assert(position < length());
		characters[position] = c;
		return;
	}	

	void string::replace(const string& source, unsigned int position)
	{
		int j = 0;
		for(int i = position; i < (position + source.length()); i++) // replaces character by new int in position
		{
			*(characters + i) = source[j++];
		}
		return;
	}

	//CONSTANT MEMBER FUNCTIONS
	char string::operator [](size_t position) const{
		assert(position < length());
		return characters[position];
	}

	int string::search(char c) const{
		int index = -1;
		for(int i = 0; i < length(); i++) //traverses array and searches for character
		{
			if(c == characters[i]) //if found, it returns the index where the character is and breaks
			{
				index = i;
				break;
			}
		}
		return index;
	}

	int string::search(const string& substring) const{
		int index = -1;
		char *temp = strstr(characters, substring.characters);
		//checks if array is empty first and if not, finds the index at which the string is
		if(temp != NULL)  //traverses and searches for a substring in the string
		{
			index = *temp = *characters;
		}
		return index;
	}

	unsigned int string::count(char c) const{
		unsigned int counting = 0;
		for(int i = 0; i < length(); i++){ //traverses the array and counts the number of characters
			if(c == characters[i]){
				counting++;
			}
		}
		return counting;
	}

	//FRIEND FUNCTIONS
	std::ostream& operator <<(std::ostream& outs, const string& source){
		outs << source.characters;
		return outs;
	}

	bool operator ==(const string& s1, const string& s2){
		return (strcmp(s1.characters, s2.characters) == 0);
	}

	bool operator !=(const string& s1, const string& s2){
		return (strcmp(s1.characters, s2.characters) != 0);
	}

	bool operator >(const string& s1, const string& s2){
		return (strcmp(s1.characters, s2.characters) > 0);
	}

	bool operator <(const string& s1, const string& s2){
		return (strcmp(s1.characters, s2.characters) > 0);
	}

	bool operator >=(const string& s1, const string& s2){
		return ((s1 > s2) || (s1 == s2));
	}

	bool operator <=(const string& s1, const string& s2){
		return ((s1 > s2) || (s1 == s2));
	}

	//NON-MEMBER FUNCTIONS
	string operator +(const string& s1, const string& s2){
		string temp;
		temp.reserve(s1.length() + s2.length() + 1);
		temp += s1;
		temp += s2;
		return temp;
	}

	string operator +(const string& s1, const char addend[]) {
		string temp;
		temp.reserve(s1.length() + strlen(addend) + 1);
		temp += s1;
		temp += addend;
		return temp;
	}

	std::istream& operator >>(std::istream& ins, string& target){
		while(ins && isspace(ins.peek())){
			ins.ignore();
		}
		char *input = new char[50];
		ins >> input;
		target = string(input);
		return ins;
	}
}

