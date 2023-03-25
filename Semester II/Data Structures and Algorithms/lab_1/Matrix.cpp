#include "Matrix.h"
#include <exception>
using namespace std;

// 1) ADT Matrix –represented as a sparse matrix, using a dynamic array of triples <line, column, value>  (value ≠0),
// ordered  lexicographically  considering  the  <line,  column>  of  every element.

Matrix::Matrix(int nrLines, int nrCols)
{
    this->nr_of_lines = nrLines;
    this->nr_of_columns = nrCols;
    this->size = nrLines * nrCols;
    this->values = new TValue [nrLines * nrCols];

    this->initializeMatrix();

}

void Matrix::initializeMatrix()
{//Θ(this->size)
    int line = this->nr_of_lines - 1;
    int column = this->nr_of_columns - 1;

    for (int i = this->size -1; i >= 0; --i)
    {
            this->values[i].first.first = line;
            this->values[i].first.second = column;

            this->values[i].second = NULL_TELEM;

            column--;
            if(column == -1)
            {
                line--;
                column = this->nr_of_columns - 1;
            }
    }
}

int Matrix::nrLines() const
{//O(1)
	return this->nr_of_lines;
}


int Matrix::nrColumns() const
{//O(1)
	return this->nr_of_columns;
}


TElem Matrix::element(int i, int j) const
{//O(this->size)

    if(i < 0 || i >= this->nr_of_lines)
        throw std::exception();
    if(j < 0 || j >= this->nr_of_columns)
        throw std::exception();


    for (int k = 0; k < this->size; ++k)
    {
        if(this->values[k].first.first == i && this->values[k].first.second == j)
            return this->values[k].second;
    }

}

TElem Matrix::modify(int i, int j, TElem e)
{//Θ(this->size)
    if(i < 0 || i >= this->nr_of_lines)
        throw std::exception();
    if(j < 0 || j >= this->nr_of_columns)
        throw std::exception();
    int prev_element = -11111;

    for (int k = 0; k < this->size; ++k)
    {
        if(this->values[k].first.first == i && this->values[k].first.second == j)
        {
            prev_element = this->values[k].second;
            this->values[k].second = e;
        }
    }

    return prev_element;
}

int Matrix::numberOfNonZeroElems(int column)const
{
    //Θ(this->size)
    if(column < 0 || column >= this->nr_of_columns)
        throw std::exception();

    int nr_of_non_zero_elems = 0;

    for (int k = 0; k < this->size; ++k)
    {
        if(this->values[k].first.second == column && this->values[k].second != 0)
            nr_of_non_zero_elems++;
    }
    return nr_of_non_zero_elems;
}

