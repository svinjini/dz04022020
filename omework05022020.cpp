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
	std::cin >> x;
	List second;
    return 0;
}

