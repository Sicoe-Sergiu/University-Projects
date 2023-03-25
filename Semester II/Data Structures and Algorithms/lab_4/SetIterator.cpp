#include "SetIterator.h"
#include "Set.h"
#include "exception"

SetIterator::SetIterator(const Set& m) : set(m)
{
    this->index = 0;
    this->current_node = this->set.set[0];
    this->first();
}


void SetIterator::first()
{
    if(this->set.isEmpty())
        return;

    this->index = 0;

    while(this->set.set[index] == nullptr)
    {
        this->index++;
    }

    this->current_node = this->set.set[index];
}


void SetIterator::next()
{
    if(this->set.isEmpty() || !this->valid())
        throw std::exception();

    if(this->current_node == nullptr)
        throw std::exception();

    if(this->current_node->getNext() != nullptr)
        this->current_node = this->current_node->getNext();

    else if(this->current_node->getNext() == nullptr)
    {
        ++index;
        while (this->set.set[index] == nullptr)
        {
            this->index++;
            if (index == this->set.cap)
                return;
        }
        this->current_node = this->set.set[index];
    }

}


TElem SetIterator::getCurrent()
{
    if(!this->valid())
        throw std::exception();
	return this->current_node->getValue();
}

bool SetIterator::valid() const
{
    if(this->set.isEmpty())
        return false;

    if(this->index == this->set.cap)
        return false;

    return true;
}



