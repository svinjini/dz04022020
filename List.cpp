#include "stdafx.h"
#include "List.h"


List::List()
{
	head = nullptr;
	tail = nullptr;
}
List& operator &(const List& ob, const List& ob1) {
	List *listok = new List();
	return *listok;
}
List& operator |(const List& ob, const List& ob1) {
	List *listok = new List();
	return *listok;
}
std::ostream& operator<<(std::ostream& out, const List& ob) {
	List::Node* current;
	if (ob.head != nullptr) {
		current = ob.head;
		while (current != nullptr) {
			out << current->value<<std::endl;
			current = current->next;
		}
		return out;
	}
	else {
		if (ob.tail != nullptr) {
			out << ob.tail->value;
			return out;
		}
		else {
			std::cout << "NO DATA" << std::endl;
		}
	}
}
/*bool& List::operator ==(List& ob) {
	List *listok = new List();
	return false;
}*/
List& List::operator +=(int x) {
	Node* temp;
	if (tail == nullptr) {
		tail = new Node();
		tail->value = x;
	}
	else {
		if (isSame(x) != true) {
			temp = head;
			head = new Node();
			head->value = x;
			if (temp == nullptr) {
				head->next = tail;
			}
			else {
				head->next = temp;
			}
			Sort();
		}
	}
	return *this;
}
void List::deleteList() {
	Node* temp;
	while (head != tail) {
		temp = head->next;
		deleteNode(head);
		head = temp;
	}
	deleteNode(head);
}
void List::deleteNode(Node* a) {
	delete a;
}
List::List(const List& ob) {

}
void List::Sort() {
	Node* current=head;
	int x;
	while((current!=tail) && (current->value>current->next->value)){
		x = current->value;
		current->value = current->next->value;
		current->next->value = x;
		current = current->next;
	}
}
bool List::isSame(int x) {
	Node* current;
	if (head != nullptr) {
		current = head;
		while (current != nullptr) {
			if (current->value == x) {
				return true;
				break;
			}
			current = current->next;
		}
		return false;
	}
	else {
		if (x == tail->value) {
			return true;
		}
		else {
			return false;
		}
	}
}
List::List(List&& ob) {
}
List::~List()
{
	deleteList();
}
