#include <exception>
#include "BagIterator.h"
#include "Bag.h"

using namespace std;


BagIterator::BagIterator(const Bag& c): bag(c)
{
    if(bag.nr_of_elements != 0)
    {
        this->current_elem = bag.array[0].first;
        this->current_elem_pos = 1;
        this->current_array_pos = 0;
    }
    else
    {
        this->current_elem = NULL_TELEM
        this->current_elem_pos = -1;
        this->current_array_pos = -1;
    }

}

void BagIterator::first()
{
    this->current_elem = bag.array[0].first;
    this->current_elem_pos = 1;
    this->current_array_pos = 0;
}


void BagIterator::next()
{
    if(this->current_array_pos == -1 || this->current_array_pos > bag.size_of_array_fields || !this->valid())
        throw std::exception();

    if(this->current_elem_pos == bag.array[this->current_array_pos].second)
    {
        this->current_array_pos++;
        this->current_elem = bag.array[this->current_array_pos].first;
        this->current_elem_pos = 1;
    }
    else
    {
        this->current_elem_pos++;
    }
}


bool BagIterator::valid() const
{
    if(this->current_array_pos == -1 || this->current_array_pos > bag.size_of_array_fields || this->current_elem == -111111)
        return false;

	return true;
}



TElem BagIterator::getCurrent() const
{
    if(this->current_array_pos == -1 || this->current_array_pos > bag.size_of_array_fields || !this->valid())
        throw std::exception();

	return this->current_elem;
}
