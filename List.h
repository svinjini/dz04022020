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
	List();
	void deleteList();
	void deleteNode(Node* a);
	List& operator +=(int x);
	void Sort();
	List(const List& ob);
	List(List&& ob);
	~List();
	friend bool operator ==(List& ob, List& ob1);
	friend List& operator &(List& ob1, List& ob2);
	friend List& operator |(List& ob1, List& ob2);
	int count();
	bool isSame(int x);
	List& operator =(List& obj);
	void merge(List& ob);
	friend std::ostream& operator<<(std::ostream& out, const List& ob);
};


