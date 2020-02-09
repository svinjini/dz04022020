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
	friend bool operator ==(List& ob, List& ob1);
	friend List& operator &(List& ob, List& ob1);
	friend List& operator |(const List& ob, const List& ob1);
	int count();
	bool isSame(int x);
	List& operator =(List& obj);
	List& merge(List& ob);
	friend std::ostream& operator<<(std::ostream& out, const List& ob);
	ostream& operator<<(std::ostream& out, const List& ob);
};

