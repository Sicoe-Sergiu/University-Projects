#include "SMMIterator.h"
#include "SortedMultiMap.h"
#include <iostream>
#include <vector>
#include <exception>
using namespace std;

SortedMultiMap::SortedMultiMap(Relation r)
{
    this->root = new BSTNode;

    this->ascending = r;
    this->nr_of_elems = 0;
    this->nr_of_nodes = 0;

}

void SortedMultiMap::add(TKey c, TValue v)
{

    if(search(c).size() == 0)
        keys.push_back(c);

    if (this->nr_of_elems == 0)
    {
        TElem elem;
        elem.first = c;
        elem.second = v;

        this->root->elements.push_back(elem);
        this->nr_of_elems++;
        this->nr_of_nodes++;
        return;
    }


    TElem elem;
    elem.first = c;
    elem.second = v;

    BSTNode *current_node = this->root;


    while(current_node != nullptr)
    {
        if (current_node->elements[0].first == c)
        {
            current_node->elements.push_back(elem);
            this->nr_of_elems++;
            return;
        }

        if (current_node->elements[0].first >= c && this->ascending)
        {
            current_node = current_node->left;

        } else if (current_node->elements[0].first < c && this->ascending)
        {
            current_node = current_node->right;

        }else if (current_node->elements[0].first >= c && !this->ascending)
        {
            current_node = current_node->right;

        } else if (current_node->elements[0].first < c && !this->ascending)
        {
            current_node = current_node->left;

        }

    }



    current_node = this->root;
    BSTNode* new_node = new BSTNode;
    new_node->elements.push_back(elem);
    new_node->right = nullptr;
    new_node->left = nullptr;

    while(current_node != nullptr)
    {
        if( c <= current_node->elements[0].first && this->ascending)
        {
            if (current_node->left == nullptr)
            {
                current_node->left = new_node;
                current_node->left->left = nullptr;
                current_node->left->right = nullptr;
                this->nr_of_elems++;
                this->nr_of_nodes++;
                return;
            }
            current_node = current_node->left;

        } else if( c <= current_node->elements[0].first && !this->ascending)
        {
            if (current_node->right == nullptr)
            {
                current_node->right = new_node;
                current_node->right->left = nullptr;
                current_node->right->right = nullptr;
                this->nr_of_elems++;
                this->nr_of_nodes++;
                return;
            }
            current_node = current_node->right;

        } else if( c > current_node->elements[0].first && this->ascending)
        {
            if (current_node->right == nullptr)
            {
                current_node->right = new_node;
                current_node->right->left = nullptr;
                current_node->right->right = nullptr;
                this->nr_of_elems++;
                this->nr_of_nodes++;
                return;
            }
            current_node = current_node->right;

        }else if( c > current_node->elements[0].first && !this->ascending)
        {
            if (current_node->left == nullptr)
            {
                current_node->left = new_node;
                current_node->left->left = nullptr;
                current_node->left->right = nullptr;
                this->nr_of_elems++;
                this->nr_of_nodes++;
                return;
            }
            current_node = current_node->left;
        }

    }

}

vector<TValue> SortedMultiMap::search(TKey c) const
{

    BSTNode *current_node = this->root;
    vector<TValue> values;

    if(this->root->elements.size() == 0)
        return values;

    while(current_node != nullptr)
    {
        if (current_node->elements[0].first == c)
        {

            for (int index = 0; index < current_node->elements.size(); ++index)
            {
                values.push_back(current_node->elements[index].second);
            }

        }

        if (current_node->elements[0].first >= c && this->ascending)
        {
            current_node = current_node->left;

        } else if (current_node->elements[0].first < c && this->ascending)
        {
            current_node = current_node->right;

        }else if (current_node->elements[0].first >= c && !this->ascending)
        {
            current_node = current_node->right;

        } else if (current_node->elements[0].first < c && !this->ascending)
        {
            current_node = current_node->left;

        }

    }

	return values;
}

BSTNode* SortedMultiMap::deleteNode(BSTNode *node, TKey key)
{
    if (node == nullptr)
        return nullptr;
    if(key < node->elements[0].first)
    {
        node->left = deleteNode(node->left, key);
    }
    else if(key > node->elements[0].first)
    {
        node->right = deleteNode(node->right, key);
    }

    if(node->left == nullptr && node->right == nullptr)
    {
        node = nullptr;
        return nullptr;
    }

    if(node->left == nullptr || node->right == nullptr)
    {
        auto temp = node->left ? node->left : node->right;
        node = nullptr;
        return temp;
    }

    if(node->left != nullptr && node->right != nullptr)
    {
        auto temp = node->right;
        while(temp->left != nullptr)
            temp = temp->left;

        node->elements = temp->elements;

        node->right = deleteNode(node->right, node->elements[0].first);
        return node;
    }

}

bool SortedMultiMap::remove(TKey c, TValue v)
{
    BSTNode *current_node = this->root;
    TElem elem_to_delete;
    elem_to_delete.first = c;
    elem_to_delete.second = v;

    if(root == nullptr)
        return false;

    if(search(c).size() == 0)
        return false;

    if(this->root->elements.size() == 1 && this->root->elements[0].first == c && this->root->elements[0].second == v)
    {
        this->root = nullptr;
        nr_of_nodes--;
        nr_of_elems--;
        return true;
    }

    while(current_node != nullptr)
    {

        if(current_node->elements.size() != 1)
        {
            for (auto it = current_node->elements.begin(); it != current_node->elements.end(); it++)
            {
                if(it->first == c && it->second == v)
                {
                    current_node->elements.erase(it);
                    nr_of_elems--;
                    return true;
                }
            }
        }

        if (current_node->right->elements[0].first == c && current_node->right->elements[0].second == v && current_node->right->elements.size() == 1)
        {
            current_node->right = deleteNode(current_node->right, c);
            nr_of_nodes--;
            nr_of_elems--;
            return true;
        }

        if (current_node->left->elements[0].first == c && current_node->left->elements[0].second == v && current_node->left->elements.size() == 1)
        {
            current_node->left = deleteNode(current_node->left, c);
            nr_of_nodes--;
            nr_of_elems--;
            return true;

        }


        if (current_node->elements[0].first >= c && this->ascending)
        {
            current_node = current_node->left;

        } else if (current_node->elements[0].first < c && this->ascending)
        {
            current_node = current_node->right;

        }else if (current_node->elements[0].first >= c && !this->ascending)
        {
            current_node = current_node->right;

        } else if (current_node->elements[0].first < c && !this->ascending)
        {
            current_node = current_node->left;
        }

    }

    return false;
}


int SortedMultiMap::size() const
{
	return this->nr_of_elems;
}


std::vector<int> SortedMultiMap::returnKeys()
{
    return keys;
}


bool SortedMultiMap::isEmpty() const
{
	return (this->nr_of_elems == 0 && this->nr_of_nodes == 0);
}

SMMIterator SortedMultiMap::iterator() const
{
	return SMMIterator(*this);
}

SortedMultiMap::~SortedMultiMap()
{
	//TODO - Implementation
}
