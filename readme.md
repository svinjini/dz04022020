## Д.З. Класс Односвязный Список

#### Компилируется с использованием фич С++11
Для gcc опции --std=c++11 или c++14

	make
	rm -f list
	g++ -g --std=c++11 *.cpp -o list


#### Program output

	./list
	first = 1 2 5 7

	second = 1 2 5 10

	copy(first) = 1 2 5 7

	first & second = 1 2 5

	fourth =  first|second = 1 2 5 7 10

	first.merge(fourth) = 1 2 5 7 10

	fifth(std::move(first)) = 1 2 5 7 10


#### В "старом" стандарте не работает 

	gcc version 5.4.0 20160609
	g++ -g --std=c++98 *.cpp -o list
	In file included from homework-05022020.cpp:3:0:
	List.h:21:11: error: expected ‘,’ or ‘...’ before ‘&&’ token
	  List(List&& ob);
			   ^
	List.h:21:16: error: invalid constructor; you probably meant ‘List (const List&)’
	  List(List&& ob);
					^
	List.h: In constructor ‘List::Node::Node(int)’:
	List.h:10:32: error: ‘nullptr’ was not declared in this scope
	   Node(int v) : value(v), next(nullptr) { }
                                ^

