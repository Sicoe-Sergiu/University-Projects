#include <assert.h>
#include "Matrix.h"

using namespace std;

void testAll() { 
	Matrix m(4, 4);
	assert(m.nrLines() == 4);
	assert(m.nrColumns() == 4);	

    m.modify(1, 1, 5);
	assert(m.element(1, 1) == 5);

    TElem old = m.modify(1, 1, 6);
	assert(m.element(1, 2) == NULL_TELEM);
	assert(old == 5);


    m.modify(0, 3, 5);
    m.modify(1, 3, 5);
    m.modify(2, 3, 0);
    m.modify(3, 3, 5);

    int nr_of_non_zero = m.numberOfNonZeroElems(3);
    assert(nr_of_non_zero == 3);

}