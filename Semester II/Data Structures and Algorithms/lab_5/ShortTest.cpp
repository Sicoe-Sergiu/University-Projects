#include <assert.h>

#include "SortedMultiMap.h"
#include "SMMIterator.h"
#include <exception>
#include <vector>

using namespace std;

bool relation1(TKey cheie1, TKey cheie2) {
	if (cheie1 <= cheie2)
    {
		return true;
	}
	else {
		return false;
	}
}

void testAll(){
	SortedMultiMap smm = SortedMultiMap(relation1);
	assert(smm.size() == 0);
	assert(smm.isEmpty());
    smm.add(1,2);
    smm.add(1,3);


    assert(smm.size() == 2);
    assert(!smm.isEmpty());
    vector<TValue> v= smm.search(1);
    assert(v.size()==2);
    v= smm.search(3);
    assert(v.size()==0);
    assert(smm.remove(1, 2) == true);
    assert(smm.remove(1, 3) == true);
    assert(smm.remove(2, 1) == false);
    assert(smm.remove(5, 1) == false);
    assert(smm.remove(3, 1) == false);
    assert(smm.remove(9, 1) == false);
    assert(smm.isEmpty());


    SortedMultiMap smm2 = SortedMultiMap(relation1);

    smm2.add(1,2);
    smm2.add(1,3);
    smm2.add(2,2);
    smm2.add(3,3);
    smm2.add(4,2);
    smm2.add(5,3);
    assert(smm2.returnKeys().size() == 5);
}

