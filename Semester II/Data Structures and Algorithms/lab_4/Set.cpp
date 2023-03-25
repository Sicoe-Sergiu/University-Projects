#include "Set.h"
#include "SetITerator.h"
#include <iostream>

Set::Set()
{
    this->set = new SLL_HT_Node*[cap];

    for (int i = 0; i < cap; ++i)
        this->set[i] = nullptr;

    this->set_size = 0;
    this->biggest_index = 0;
}

int Set::hashFunction(TElem elem) const
{
    return (int) std::abs(elem) % cap;
}

bool Set::add(TElem elem)
{
    if(search(elem))
        return false;

    int index = hashFunction(elem);

    if(index > this->biggest_index)
        this->biggest_index = index;

    if(this->set[index] == nullptr)
    {
        this->set[index] = new SLL_HT_Node(elem);
        this->set_size++;
        return true;
    }
    else
    {
        SLL_HT_Node *node = this->set[index];
        SLL_HT_Node *new_node = new SLL_HT_Node(elem);

        while(node != nullptr) {
            if (node->getNext() == nullptr)
            {
                node->setNext(new_node);
                this->set_size++;
                return true;
            }
            node->setNext(node);
        }
    }

	return false;
}


bool Set::remove(TElem elem)
{
	int index = hashFunction(elem);
    if(!search(elem))
        return false;

    SLL_HT_Node* node = this->set[index];

    SetIterator it(*this);

    SLL_HT_Node* sll_head = it.current_node;

    int sem = 1;

    while (it.current_node != nullptr)
    {
        if(sll_head == node && it.current_node->getValue() == elem && sem == 1)
        {
            node = node->getNext();
            this->set[index] = node;
            this->set_size--;
            return true;
        }
        else if (sll_head == node && it.current_node->getNext()->getValue() == elem)
        {
            it.current_node->setNext(it.current_node->getNext()->getNext());
            this->set[index] = it.current_node;
            this->set_size--;
            return true;
        }

        int ind = it.index;
        it.next();
        sem = 0;
        if(ind != it.index)
        {
            sll_head = it.current_node;
            sem = 1;
        }
    }
	return false;
}

bool Set::search(TElem elem) const
{
	int index = hashFunction(elem);
    SLL_HT_Node *node = this->set[index];

    while(node != nullptr)
    {
        if(node->getValue() == elem)
            return true;
        node = node->getNext();
    }

	return false;
}


int Set::size() const
{
	return this->set_size;
}


bool Set::isEmpty() const
{
	return this->set_size == 0;
}


Set::~Set()
{
    for (int i = 0; i < cap; ++i)
    {
        delete this->set[i];
    }
}

SetIterator Set::iterator() const {
	return SetIterator(*this);
}


int Set::difference(const Set& set)
{
    SetIterator it(*this);
    int ct = 0;

    while (it.valid())
    {
        if(set.search(it.current_node->getValue()))
        {
            this->remove(it.current_node->getValue());
            ct++;
        }
        it.next();
    }
    return ct;

}

int Set::getRange()
{
    if( isEmpty())
        return -1;

    int difference;
    int min = 9999;
    int max = -9999;

    SetIterator it(*this);

    while (it.valid())
    {
        if(it.current_node->getValue() > max)
            max = it.current_node->getValue();

        if(it.current_node->getValue() < min)
            min = it.current_node->getValue();

        it.next();
    }

    return max - min;


}