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
	std::cout << "It's first" << std::endl << first;
	
    List second;
	second += 1;
	second += 2;
	second += 5;
	second += 2; // should not get into list
	second += 10;
    assert(first.count() == 4);
	std::cout << "It's second " << std::endl << second;
	
    List copy(first);
    assert(copy.count() == 4);
	std::cout << "It's copy: " << std::endl << copy;
	
    List third;
	third = (first & second);
    assert(third.count() == 3);
	std::cout << "operator &: " << std::endl << third;
	
    List fourth;
	fourth = (first | second);
	std::cout << "operator |: " << std::endl << fourth;

	first.merge(fourth);
	std::cout << "It's merge:" << std::endl << first;
	

    //List f = std::move(first);

    List fifth(std::move(first));
	std::cout << "It's fifth:" << std::endl << fifth;


    return 0;
}

