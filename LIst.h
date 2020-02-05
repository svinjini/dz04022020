#pragma once
#include <iostream>
class List
{
public:
	struct Node {
		int value;
		Node* next;
		Node() {
			value = 0;
			next = nullptr;
		}
	};
	Node* head;
	Node* tail;
	List();
	void deleteList();
	void deleteNode(Node* a);
	List& operator +=(int x);
	void Sort();
	List(const List& ob);
	List(List&& ob);
	~List();
	bool& operator ==(List& ob);
	friend List& operator &(const List& ob, const List& ob1);
	friend List& operator |(const List& ob, const List& ob1);
	bool isSame(int x);
	friend std::ostream& operator<<(std::ostream& out, const List& ob);
};

