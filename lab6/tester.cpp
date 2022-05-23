#include "node.h"
#include <iostream>

using namespace std;
using namespace coen79_lab6;


int main(int argc, char const *argv[]) {
    
    node *my_list = NULL;

    list_head_insert(my_list, 1.5);
    list_head_insert(my_list, 9);
    list_head_insert(my_list, 8.5);
    list_head_insert(my_list, 2);
    list_head_insert(my_list, 4.5);
    list_head_insert(my_list, 6);
    list_head_insert(my_list, 2.5);
    list_head_insert(my_list, 1.3);

    cout << "The list: ";
    list_print(my_list);
	cout << endl; 
    
    node *head, *tail;

    list_piece(NULL,NULL,head,tail);
    cout << "Empty: ";
    list_print(head);

    list_piece(my_list,my_list,head,tail);
    cout << "Both at head: ";
    list_print(head);

    cout << "Three from head: ";
   	list_print(list_copy_segment(my_list,1,3));

    cout << "Three in middle: ";
    list_print(list_copy_segment(my_list,3,5));

    cout << "Three on end: ";
    list_print(list_copy_segment(my_list,6,list_length(my_list)));
        
    list_insert_at(my_list, 4.5, 1);
    cout << "Inserting 4.5 at front:\n\t";
    list_print(my_list);

    list_insert_at(my_list, 8.88, list_length(my_list)+1);
    cout << "Inserting 8.88 at back:\n\t";
    list_print(my_list);

    list_insert_at(my_list, 7, 2);
    list_insert_at(my_list, 7, 2);
    
	cout << "The list: ";
   	list_print(my_list);

    cout << "Number of 7's: " << list_occurrences(my_list, 7) << endl;
    cout << "Number of 1's: " << list_occurrences(my_list, 1) << endl;

    cout << "The list: ";
    list_print(my_list);

    cout << "Removing last item:\n\t";
    list_remove_at(my_list, list_length(my_list));
    list_print(my_list);

    cout << "Removing fifth item:\n\t";
    list_remove_at(my_list, 5);
    list_print(my_list);

    node* head_ptr = NULL;
    list_head_insert(head_ptr, 1);
    list_head_insert(head_ptr, 1);
        
    list_print(head_ptr);
	
    list_remove_dups(head_ptr);
    list_print(head_ptr);

    node* head_ptr2 = NULL;
    list_head_insert(head_ptr2, 10);
    list_head_insert(head_ptr2, 9);
    list_head_insert(head_ptr2, 8);
    list_head_insert(head_ptr2, 7);

	return 0;
}
