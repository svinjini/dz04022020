#include <iostream>
#include <assert.h>
#include "List.h"

int main()
{
	List first;
	first += 1;
	first += 5;
	first += 2;
	first += 7;
    assert(first.count() == 4);
	std::cout << "first =" << first;
	
    List second;
	second += 1;
	second += 2;
	second += 5;
	second += 2; // should not get into list
	second += 10;
    assert(first.count() == 4);
	std::cout << "second ="  << second;
	
    List copy(first);
    assert(copy.count() == 4);
	std::cout << "copy(first) =" << copy;
	
    List third;
	third = (first & second);
    assert(third.count() == 3);
	std::cout << "first & second =" << third;
	
    List fourth;
	fourth = (first | second);
	std::cout << "fourth =  first|second =" << fourth;

	first.merge(fourth);
	std::cout << "first.merge(fourth) =" << first;
	
    List fifth(std::move(first));
	std::cout << "fifth(std::move(first)) =" << fifth;

    List a, b;
    assert (a == b);
    a += 9;
    assert (a != b);
    b += 9;
    assert (a == b);
    a += 8;
    assert (a != b);
    return 0;
}

