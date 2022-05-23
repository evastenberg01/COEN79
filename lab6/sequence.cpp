#include <iostream>
#include <algorithm>
#include <cassert>
#include "sequence.h"
#include "node.h"

using namespace std;

namespace coen79_lab6
{
	//Default private member variable initialization function
	void sequence::init()
	{
		head_ptr = NULL;
		tail_ptr = NULL;
		cursor = NULL;
		precursor = NULL;
		many_nodes = 0; //counter
	}
	//CONSTRUCTOR
	sequence::sequence(){
		init();
	}

	//COPY CONSTRUCTOR
	sequence::sequence(const sequence& source)
	{
		init();
		*this = source;
	}

	sequence::~sequence()
	{
		list_clear(head_ptr);
		many_nodes = 0;
	}

	//MODIFICATION MEMBER FUNCTIONS
	void sequence::start()
	{
		precursor = NULL;
		cursor = head_ptr;
		return;
	}
		
	void sequence::end()
	{
		cursor = tail_ptr;
		if(head_ptr == tail_ptr)
		{
			precursor = NULL;
		}
		else
		{
			precursor = head_ptr;
			while(precursor->link() != cursor){
				precursor = precursor->link();
			}
		}
		return;
	}

	void sequence::advance()
	{
		assert(is_item());
		
		precursor = cursor;
		cursor = cursor->link();
		return;
	}

	void sequence::insert(const value_type& entry){
		if(head_ptr == NULL)// checks if the list is empty
		{
			list_head_insert(head_ptr, entry);
			cursor = head_ptr;
			precursor = NULL;
			tail_ptr = head_ptr;
		}
		else if(is_item() && cursor == head_ptr) //if the cursor is at the head
		{
			list_head_insert(head_ptr, entry);
			cursor = head_ptr;
			precursor = NULL;
		}
		else if(is_item() && cursor != head_ptr) //if cursor is anywhere but head
		{
			list_insert(precursor, entry);
			cursor = precursor->link();
		}
		else if(!is_item())//if the cursor is null
		{
			list_head_insert(head_ptr, entry);
			cursor = head_ptr;
			precursor = NULL;
		}
		many_nodes++;
		return;
	}

	void sequence::attach(const value_type& entry)
	{
		if(head_ptr == NULL)
		{
			list_head_insert(head_ptr, entry);
			cursor = head_ptr;
			precursor = NULL;
			tail_ptr = head_ptr;
		}
		else if(is_item() && many_nodes == 1) //if head is equal to tail
		{
			list_insert(head_ptr, entry);
			precursor = head_ptr;
			tail_ptr = precursor->link();
			cursor = tail_ptr;
		}
		else if(is_item() && many_nodes > 1 && cursor == head_ptr) //inserting at the head with more than one entry
		{
			list_insert(head_ptr, entry);
			precursor = head_ptr;
			cursor = precursor->link();
		}
		else if(is_item() && cursor != head_ptr) //inserting in the middle
		{
			if(cursor != tail_ptr)
			{
				list_insert(cursor, entry);
				advance();
			}
			else //inserting at tail
			{
				list_insert(tail_ptr, entry);
				tail_ptr = cursor->link();
				precursor = cursor;
				cursor = tail_ptr;
			}
		}
		else if(!is_item() && many_nodes > 0) //cursor is null but not empty
		{
			list_insert(tail_ptr, entry);
			precursor = tail_ptr;
			cursor = precursor->link();
			tail_ptr = cursor;
		}
		many_nodes++;
		return;
	}

	//MODIFICATION MEMBER FUNCTIONS
	void sequence::operator =(const sequence& source)
	{
		if(this == &source)
			return;

		list_clear(head_ptr);
		many_nodes = 0;
		node* tmp_tail;
		list_copy(source.head_ptr, head_ptr, tmp_tail);
		cursor = head_ptr;
		tail_ptr = tmp_tail;
		node* tmp = source.head_ptr;
		precursor = head_ptr;
		if(source.cursor == NULL)
		{
			cursor = NULL;
			precursor = tail_ptr;
		}
		else
		{
			while(tmp != source.precursor)
			{
				tmp = tmp->link();
				precursor = precursor->link();
			}
			if(precursor != NULL)
				cursor = precursor->link();
		}
		many_nodes = source.many_nodes;
	}

	void sequence::remove_current()
	{
		assert(is_item());
		if(head_ptr->link() == NULL) //only one item in the list
		{
			delete cursor;
			head_ptr = NULL;
			tail_ptr = NULL;
			precursor = NULL;
			cursor = NULL ;
		}
		else if(cursor == head_ptr && head_ptr->link() != NULL) //cursor at head
		{
			cursor = head_ptr->link();
			list_head_remove(head_ptr);
			precursor = NULL;
		}
		else if(cursor == tail_ptr && many_nodes > 1)//cursor at tail
		{
			tail_ptr = precursor;
			delete cursor;
			cursor = NULL;
			tail_ptr->set_link(NULL);
		}
		else if(cursor != head_ptr && cursor != tail_ptr) //removing from middle
		{
			precursor->set_link(cursor->link());
			delete cursor;
			cursor = precursor->link();
		}
		many_nodes--;
	}

	//CONSTANT MEMBER FUNCTIONS
	sequence::size_type sequence::size() const {
		return many_nodes;
	}

	bool sequence::is_item( ) const{
		if(cursor == NULL)
			return false;
		else
			return true;
	}

	sequence::value_type sequence::current( ) const{
		assert(is_item());
		return cursor->data();
	}
}


			
		


				



