#pragma once
//DO NOT INCLUDE SETITERATOR

//DO NOT CHANGE THIS PART
#define NULL_TELEM -111111
#define CAP 100000
typedef int TElem;
class SetIterator;


class SLL_HT_Node
{
private:
    TElem value;
    SLL_HT_Node *next;
public:
    explicit SLL_HT_Node(TElem elem) { this->value = elem; this->next = nullptr; }
    TElem getValue() const{ return this->value; }
    void setValue(TElem val) { this->value = val; }
    SLL_HT_Node *getNext(){ return this->next; }
    void setNext(SLL_HT_Node * node) { this->next = node; }
};

class Set {
	//DO NOT CHANGE THIS PART
	friend class SetIterator;

    private:

        static const int cap = CAP;
        SLL_HT_Node **set;
        int set_size;
        int biggest_index;


public:

        int hashFunction(TElem elem) const;

        //implicit constructor
        Set();

        //adds an element to the set
		//returns true if the element was added, false otherwise (if the element was already in the set and it was not added)
        bool add(TElem e);

        //removes an element from the set
		//returns true if e was removed, false otherwise
        bool remove(TElem e);

        //checks whether an element belongs to the set or not
        bool search(TElem elem) const;

        //returns the number of elements;
        int size() const;

        //check whether the set is empty or not;
        bool isEmpty() const;

        //return an iterator for the set
        SetIterator iterator() const;

        // destructor
        ~Set();

    int difference(const Set &set);

    int getRange();
};





