#pragma once
#include <utility>
//DO NOT CHANGE THIS PART
typedef int TElem;
#define NULL_TELEM 0

typedef int TLine;
typedef int TCol;

typedef std::pair<TLine, TCol> TCoords;
typedef std::pair<TCoords, TElem>TValue;

#define NULL_COORDS pair<TLine, TCol> (-111,-111)
#define NULL_VALUE pair<TCoords, TElem> (NULL_COORDS,-111)

class Matrix {

private:
    TValue *values;
    int nr_of_lines;
    int nr_of_columns;
    int size;

public:
	//constructor
	Matrix(int nrLines, int nrCols);

	//returns the number of lines
	int nrLines() const;

	//returns the number of columns
	int nrColumns() const;

	//returns the element from line i and column j (indexing starts from 0)
	//throws exception if (i,j) is not a valid position in the Matrix
	TElem element(int i, int j) const;

	//modifies the value from line i and column j
	//returns the previous value from the position
	//throws exception if (i,j) is not a valid position in the Matrix
	TElem modify(int i, int j, TElem e);

    void initializeMatrix();

    //counting the number of non-zero element from a given column
    int numberOfNonZeroElems(int column) const;
};
