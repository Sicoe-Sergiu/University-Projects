#pragma once
//DO NOT INCLUDE BAGITERATOR


//DO NOT CHANGE THIS PART
#include <utility>

#define NULL_TELEM -111111;
typedef int TElem;
typedef int nr_of_occurrences;

typedef std::pair<TElem, nr_of_occurrences> TPair;
#define CAP 100000

class BagIterator;
class Bag {

private:
    static const int cap = CAP;

    TPair array[cap];
    int next[cap]{};

    int head,tail;
    int size_of_array_fields;
    int nr_of_elements;
    int first_free;

	//DO NOT CHANGE THIS PART
	friend class BagIterator;
public:
	//constructor
	Bag();

	//adds an element to the bag
	void add(TElem e);

	//removes one occurence of an element from a bag
	//returns true if an element was removed, false otherwise (if e was not part of the bag)
	bool remove(TElem e);

	//checks if an element appearch is the bag
	bool search(TElem e) const;

	//returns the number of occurrences for an element in the bag
	int nrOccurrences(TElem e) const;

	//returns the number of elements from the bag
	int size() const;

	//returns an iterator for this bag
	BagIterator iterator() const;

	//checks if the bag is empty
	bool isEmpty() const;

	//destructor
	~Bag();

    int removeElementsWithMultipleOccurrences();
};