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
	std::cout << first << std::endl;
	List second;
	List train;
	train = first;
	std::cout<<train<<std::endl;
	second += 1;
	second += 2;
	second += 5;
	second += 2;
	second += 10;
	List copy(first);
	std::cout << copy << std::endl;
	List third;
	third = (first & second);
	std::cout<<third<<std::endl;
	std::cin >> x;
    return 0;
}
