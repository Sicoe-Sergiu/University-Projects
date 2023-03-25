#include "Bag.h"
#include "BagIterator.h"
using namespace std;


Bag::Bag()
{
    //O(this->size)
    this->head = -1;
    this->tail = -1;

    for(auto & pair : this->array)
        pair.first = NULL_TELEM

    for (int i = 0; i < cap - 1; ++i)
        this->next[i] = i+1;

    this->size_of_array_fields = 0;
    this->nr_of_elements = 0;
    this->first_free =0;
}


void Bag::add(TElem elem)
{
    //O(this->size)
	if(this->search(elem))
    {
        for(auto & pair : this->array)
        {
            if(pair.first == elem)
            {
                pair.second++;
                this->nr_of_elements++;
                break;
            }
        }
    }
    else
    {
        TPair pair;
        pair.first = elem;
        pair.second = 1;
        this->array[first_free] = pair;
        this->first_free = this->next[this->first_free];

        if(this->nr_of_elements == 0)
            head = 0;

        this->nr_of_elements++;
        this->size_of_array_fields++;
    }
}


bool Bag::remove(TElem elem)
{
    //theta(this->size)

    if(!search(elem))
        return false;

    for(auto & pair:this->array)
    {
        if(pair.first == elem)
        {
            if(pair.second > 1)
            {
                pair.second--;
                this->nr_of_elements--;
                return true;
            }
            else if(pair.second == 1)
            {
                if(this->size_of_array_fields == 1)
                {
                    this->head = -1;
                    this->first_free = 0;
                    this->nr_of_elements = 0;
                    this->size_of_array_fields = 0;
                    pair.first = NULL_TELEM
                    pair.second = 0;
                    return true;
                }
                else
                {
                    pair = this->array[this->size_of_array_fields -1];
                    this->array[this->size_of_array_fields -1].second = 0;
                    this->array[this->size_of_array_fields -1].first = NULL_TELEM
                    this->first_free = this->size_of_array_fields -1;
                    this->size_of_array_fields--;
                    this->nr_of_elements--;
                    return true;
                }
            }
        }
    }
	return false; 
}


bool Bag::search(TElem elem) const
{
    for (int i = 0; i < this->size_of_array_fields; ++i)
    {
        if(this->array[i].first == elem)
            return true;
    }
	return false; 
}

int Bag::nrOccurrences(TElem elem) const
{
    for (int i = 0; i < this->size_of_array_fields; ++i)
    {
        if(this->array[i].first == elem)
            return this->array[i].second;
    }
	return 0;
}


int Bag::size() const
{
	return this->nr_of_elements;
}


bool Bag::isEmpty() const
{
	return this->nr_of_elements == 0;
}

BagIterator Bag::iterator() const {
	return BagIterator(*this);
}


Bag::~Bag() = default;

int Bag::removeElementsWithMultipleOccurrences()
{
    int nr_of_removes = 0;

    for(auto &pair : this->array)
    {
        if(pair.second > 1)
        {
            int nr_of_elem = pair.second;

            while(nr_of_elem)
            {
                remove(pair.first);
                nr_of_removes++;
                nr_of_elem--;
            }
        }
    }
    return nr_of_removes;
}