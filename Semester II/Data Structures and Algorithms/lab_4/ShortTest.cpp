#include "ShortTest.h"
#include <assert.h>
#include <iostream>
#include "Set.h"
#include "SetIterator.h"
#include "ExtendedTest.h"

void testAll() { 
	Set s;
	assert(s.isEmpty() == true);
	assert(s.size() == 0);
	assert(s.add(5)==true);
	assert(s.add(1)==true);
	assert(s.add(10)==true);
	assert(s.add(7)==true);
	assert(s.add(1)==false);
	assert(s.add(10)==false);
	assert(s.add(-3)==true);
	assert(s.size() == 5);
	assert(s.search(10) == true);
	assert(s.search(16) == false);
    assert(s.size() == 5);
    assert(s.remove(1) == true);
	assert(s.remove(6) == false);
	assert(s.size() == 4);

	SetIterator it = s.iterator();
	it.first();
	int sum = 0;
	while (it.valid()) {
		TElem e = it.getCurrent();
		sum += e;
		it.next();
	}
	assert(sum == 19);

}

void test_activity()
{
    Set s, s1;

    s.add(5);
    s.add(4);
    s.add(9);
    s.add(3);

    s1.add(5);
    s1.add(4);
    s1.add(9);
    s1.add(3);

    s1.add(33);
    s1.add(55);
    s1.add(-2);
    s1.add(2);

    assert(s1.size() == 8);

    assert(s1.difference(s) == 4);

    assert(s1.search(5) == false);
    assert(s1.search(4) == false);
    assert(s1.search(9) == false);
    assert(s1.search(3) == false);

    assert(s1.size() == 4);


    Set s3;

    assert(s3.getRange() == -1);

    s3.add(5);
    s3.add(4);
    s3.add(9);
    s3.add(3);

    assert(s3.getRange() == 6);
}

