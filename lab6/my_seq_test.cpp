#include <iostream>
#include "sequence.h"

using namespace std;
using coen79_lab6::sequence;

void printSequence(sequence& s) {
	sequence seq(s);
	seq.start();

	while(seq.is_item()) {
		cout << seq.current() << " ";
		seq.advance();
	}
	cout << endl;
}

int main(int argc, const char * argv[])
{
	sequence seq1, seq2;
	seq1.attach(10);
	printSequence(seq1);
	seq1.attach(9);
	printSequence(seq1);
	seq1.attach(6);
	printSequence(seq1);

	seq1.insert(7);
	printSequence(seq1);
	seq1.insert(8);
	printSequence(seq1);

	seq1.remove_current();
	printSequence(seq1);
	seq1.remove_current();
	printSequence(seq1);

	seq1.attach(5);
	printSequence(seq1);
	seq1.attach(4);
	printSequence(seq1);

	seq1.start();
	seq1.remove_current();
	printSequence(seq1);

	//test remove from middle
	seq1.start();
	seq1.advance();
	seq1.remove_current();
	printSequence(seq1);

	sequence labSequence;
	cout << "Size: " << labSequence.size() << endl;
	cout << "Is_Item: " << labSequence.is_item() << endl;
	labSequence.insert(69);
	printSequence(labSequence);
	labSequence.advance();
	printSequence(labSequence);
	labSequence.advance();
	labSequence.advance();
	printSequence(labSequence);
	labSequence.remove_current();
	printSequence(labSequence);
	labSequence.attach(23);
	printSequence(labSequence);




}	
