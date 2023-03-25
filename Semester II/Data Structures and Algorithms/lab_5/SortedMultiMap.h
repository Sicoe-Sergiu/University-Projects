#pragma once
//DO NOT INCLUDE SMMITERATOR

//DO NOT CHANGE THIS PART
#include <vector>
#include <utility>
typedef int TKey;
typedef int TValue;
typedef std::pair<TKey, TValue> TElem;

#define NULL_TVALUE -111111
#define NULL_TELEM pair<TKey, TValue>(-111111, -111111);

using namespace std;
class SMMIterator;                        // 14.ADT  SortedMultiMap–using  a BST with linked  representation  on  an  array.
typedef bool(*Relation)(TKey, TKey);     // In the BST unique keys are stored with a dynamic array of the associated values.)

struct BSTNode
{
    vector<TElem> elements;
    BSTNode *left = nullptr;
    BSTNode *right = nullptr;
};

class SortedMultiMap {
	friend class SMMIterator;
    private:
		BSTNode *root;
        bool ascending;
        int nr_of_elems;
        int nr_of_nodes;
        std::vector<int> keys;

    public:

    // constructor
    SortedMultiMap(Relation r);

	//adds a new key value pair to the sorted multimap
    void add(TKey c, TValue v);

	//returns the values belonging to a given key
    vector<TValue> search(TKey c) const;

	//removes a key value pair from the sorted multimap
	//returns true if the pair was removed (it was part of the multimap), false if nothing is removed
    bool remove(TKey c, TValue v);

    //returns the number of key-value pairs from the sorted multimap
    int size() const;

    //verifies if the sorted multi map is empty
    bool isEmpty() const;

    // returns an iterator for the sorted multimap. The iterator will returns the pairs as required by the relation (given to the constructor)	
    SMMIterator iterator() const;

    // destructor
    ~SortedMultiMap();

    BSTNode* deleteNode(BSTNode *node, TKey key);

    vector<int> returnKeys();
};
