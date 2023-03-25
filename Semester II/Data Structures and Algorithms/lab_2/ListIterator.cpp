#include "ListIterator.h"
#include "IteratedList.h"
#include <exception>

ListIterator::ListIterator(const IteratedList& list) : list(list)
{
    this->head = this->list.head;
    this->tail = this->list.tail;
    this->current_node = this->list.head;
}

void ListIterator::first()
{
    this->current_node = this->list.head;
}

void ListIterator::next()
{
    if(this->current_node == nullptr)
        throw std::exception();

    this->current_node = this->current_node->next;

}

bool ListIterator::valid() const
{

    if(this->current_node == nullptr)
        return false;

    if(this->current_node->next == nullptr && this->current_node->prev == nullptr && this->current_node->data == -11111)
        return false;

    if((this->current_node != this->list.head && this->current_node->prev == nullptr) || (this->current_node != this->list.tail &&
            this->current_node->next == nullptr)) {
        return false;
    }
    return  true;
}

TElem ListIterator::getCurrent() const
{
    if(!this->valid())
        throw std::exception();

	return this->current_node->data;
}




