//FILE: sequence1.h
//Sequence Class
//COEN79

#ifndef COEN79_SEQUENCE1_H
#define COEN79_SEQUENCE1_H
#include <cstdlib>
#include <iostream>


namespace coen79_lab3 {
    
	class sequence 
	{  
   	 	public:
        	// TYPEDEF and MEMBER CONSTANTS
        	typedef double value_type;
        	typedef std::size_t size_type;
        	static const size_t CAPACITY = 30;
        
        	//CONSTRUCTOR
        	sequence( );
	
			//MODIFICATION MEMBER FUNCTIONS
			void start();//iterator reset to position 0;
			void end();//iterator points to the last item in the sequence
			void last();//the iterator is reset to CAPACITY -1, regardless of the number of items
			void advance();
			void retreat(); //The iterator's value is reduced by 1, unless already at beginning
			void insert(const value_type& entry); //inserts item after current index
			void attach(const value_type& entry); //inserts item after current index and becomes index
			void remove_current();
			void insert_front(const value_type & entry);
			void attach_back(const value_type & entry);
			void remove_front();

			size_type size( ) const{return used;}; 
			bool is_item( ) const;
			value_type current() const;
			value_type operator[] (int index) const; //returns item at a specific index
			double mean() const; //means of values stored
			double standardDeviation() const; //standard deviation of values stored
		
			friend sequence operator +=(const sequence& lhs, const sequence& rhs);
			friend sequence::value_type summation(const sequence &s);

		private:
			value_type data[CAPACITY];
			size_type used;
			size_type current_index;
};

	sequence operator +(const sequence& lhs, const sequence& rhs);

}
	
  

#endif
