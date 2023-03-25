
#include <exception>
#include <iostream>
#include "ListIterator.h"
#include "IteratedList.h"

IteratedList::IteratedList()
{
    this->head = nullptr;
    this->tail = nullptr;
    this->size_of_container = 0;

}
//O(1)
int IteratedList::size() const
{
    return this->size_of_container;
}
//O(1)
bool IteratedList::isEmpty() const
{
    return this->size_of_container == 0;
}
//O(this->size_of_container)
ListIterator IteratedList::first() const
{
    ListIterator it(*this);
    while(it.current_node != nullptr)
    {
        if(it.current_node == it.head)
            return it;
        it.next();
    }
	return ListIterator(*this);
}

//O(1)
void IteratedList::addToBeginning(TElem e)
{

    DLLNode *node = new DLLNode();
    node->data = e;
    node->prev = nullptr;
    node->next = nullptr;

    if(this->size_of_container == 0)
    {
        this->head = node;
        this->tail = node;
        this->head->next = this->tail;
        this->tail->prev = this->head;
    }
    else
    {
        this->head->prev = node;
        node->next = this->head;
        this->head = node;
    }
    this->size_of_container++;
}

//O(this->size_of_container)
TElem IteratedList::getElement(ListIterator pos) const
{
    if(!pos.valid())
        throw std::exception();

    ListIterator it(*this);

    while(it.current_node != nullptr)
    {
        if(it.current_node == pos.current_node)
            return it.current_node->data;

        it.next();
    }
	return NULL_TELEM;
}

//O(this->size_of_container)
TElem IteratedList::remove(ListIterator& pos)
{

    ListIterator it(*this);
    if(!pos.valid())
        throw std::exception();

    if(this->size_of_container == 1)
    {
        TElem del = it.head->data;
        this->head->next = nullptr;
        this->head->prev = nullptr;
        this->head->data = NULL_TELEM;
        this->tail->data = NULL_TELEM;
        this->tail->next = nullptr;
        this->tail->prev = nullptr;
        this->size_of_container--;
        return del;

    }else if(pos.current_node == it.head)
        {
            TElem del = it.head->data;
            this->head = this->head->next;
            this->head->prev = nullptr;

            this->size_of_container--;
            pos.next();
            return del;
        }
    else if(pos.current_node == it.tail)
        {
            TElem del = it.tail->data;

            this->tail = this->tail->prev;

            this->tail->next = nullptr;
            this->size_of_container--;
            pos.current_node = nullptr;
            return del;
        }
    else
        while(it.current_node != nullptr)
        {
            if(it.current_node == pos.current_node)
            {
                TElem del = it.current_node->data;

                it.current_node->prev->next = it.current_node->next;
                it.current_node->next->prev = it.current_node->prev;


                this->size_of_container--;
                pos.next();
                return del;

            }

            it.next();
        }

	return NULL_TELEM;
}

//O(this->size_of_container)
ListIterator IteratedList::search(TElem e) const
{
    ListIterator it(*this);
    while(it.current_node != nullptr)
    {
        if(it.current_node->data == e)
            return it;
        it.next();
    }
    ListIterator itt(*this);
    itt.current_node = nullptr;

    return itt;
}

//O(this->size_of_container)
TElem IteratedList::setElement(ListIterator pos, TElem e)
{
    if(!pos.valid())
        throw std::exception();

    ListIterator it(*this);
    it.first();
    while(it.current_node != nullptr)
    {
        if(it.current_node == pos.current_node)
        {
            TElem last = it.current_node->data;
            it.current_node->data = e;
            return last;
        }
        it.next();
    }
    return NULL_TELEM
}

//O(this->size_of_container)
void IteratedList::addToPosition(ListIterator& pos, TElem e)
{
    if(!pos.valid())
        throw std::exception();

    DLLNode *node = new DLLNode();
    node->data = e;
    node->next = nullptr;
    node->prev = nullptr;

    ListIterator it(*this);

    while(it.current_node != nullptr)
    {
        if(it.current_node == pos.current_node)
        {
            if(it.current_node->next == nullptr)
            {
                this->addToEnd(e);
                pos.next();
                return;
            }
            else
            {
                node->prev = it.current_node;
                node->next = it.current_node->next;

                node->next->prev = node;
                it.current_node->next = node;

                this->size_of_container++;
                pos.next();
                return;
            }
        }
        it.next();
    }
}

//O(1)
void IteratedList::addToEnd(TElem e)
{
    DLLNode *node = new DLLNode();
    node->data = e;
    node->prev = this->tail;
    node->next = nullptr;

    if(this->size_of_container == 0)
    {
        this->head = node;
        this->tail = node;
    }
    else
    {
        this->tail->next = node;
        this->tail = node;
    }
    this->size_of_container++;
}
//O(1)
IteratedList::~IteratedList()
{
    DLLNode* node;
    while(this->head != nullptr)
    {
        node = this->head;
        this->head = this->head->next;
        delete node;
    }
}

int IteratedList::removeFromKtoK(int k)
{
    if(k <= 0)
        throw std::exception();

    if(this->size_of_container < k)
        return 0;

    int nr_of_removed = 0;
    int counter = 1;

    ListIterator it(*this);
    while(it.current_node != nullptr)
    {
        if(counter == k)
        {
            this->remove(it);
            counter = 1;
            nr_of_removed++;
        }
        counter++;
        it.next();
    }

    return nr_of_removed;
}

