// omework05022020.cpp: определяет точку входа для консольного приложения.
//

#include <iostream>
#include "List.h"

int main()
{
	List first;
	first += 1;
	first += 5;
	first += 2;
	first += 7;
	int x;
	std::cout << "It's first" << std::endl << first;
	List second;
	second += 1;
	second += 2;
	second += 5;
	second += 2;
	second += 10;
	std::cout << "It's second " << std::endl << second;
	List copy(first);
	std::cout << "It's copy: " << std::endl << copy;
	List third;
	third = (first & second);
	std::cout << "operator &: " << std::endl << third;
	List fourth;
	fourth = (first | second);
	std::cout << "operator |: " << std::endl << fourth;
	first.merge(fourth);
	std::cout << "It's merge:" << std::endl << third;
	List fifth(std::move(first));
	std::cout << "It's fifth:" << std::endl << fifth;
	std::cin >> x;
	return 0;
}
