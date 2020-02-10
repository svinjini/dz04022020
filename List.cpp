#include "stdafx.h"
#include "List.h"


List::List()
{
	head = nullptr;
	tail = nullptr;
}
List& operator &(List& ob1, List& ob2) {
	List *listok = new List();
	List::Node* currentOb1=ob1.head;
	List::Node* currentOb2=ob2.head;
	while ((currentOb1!=nullptr)||(currentOb2 != nullptr)) {
		if((currentOb1!=nullptr)&&(ob2.isSame(currentOb1->value)==true)){
			List::Node* temp;
			if (listok->tail == nullptr) {
				listok->tail = new List::Node();
				listok->tail->value = currentOb1->value;
			}
			else {
				if (listok->isSame(currentOb1->value) != true) {
					temp = listok->head;
					listok->head = new List::Node();
					listok->head->value = currentOb1->value;
					if (temp == nullptr) {
						listok->head->next = listok->tail;
					}
					else {
						listok->head->next = temp;
					}
					listok->Sort();
				}
			}
		}
		if((ob1.isSame(currentOb2->value)==true)&&(currentOb2!=nullptr)){
			List::Node* temp;
			if (listok->tail == nullptr) {
				listok->tail = new List::Node();
				listok->tail->value = currentOb2->value;
			}
			else {
				if (listok->isSame(currentOb2->value) != true) {
					temp = listok->head;
					listok->head = new List::Node();
					listok->head->value = currentOb2->value;
					if (temp == nullptr) {
						listok->head->next = listok->tail;
					}
					else {
						listok->head->next = temp;
					}
					listok->Sort();
				}
			}
		}
			currentOb1 = currentOb1->next;
			currentOb2 = currentOb2->next;
	}
	return *listok;
}
int List::count() {
	int x=0;
	Node* current = head;
	while (current != nullptr) {
		x++;
		current = current->next;
	}
	return x;
}
List& operator |(List& ob1,List& ob2) {
	List *listok = new List();
	List::Node* temp;
	List::Node* currentOb1 = ob1.head;
	List::Node* currentOb2 = ob2.head;
	while ((currentOb1 != nullptr) || (currentOb2 != nullptr)) {
		if (currentOb1 != nullptr) {
			if (listok->tail == nullptr) {
				listok->tail = new List::Node();
				listok->tail->value = currentOb1->value;
			}
			else {
				if (listok->isSame(currentOb1->value) != true) {
					temp = listok->head;
					listok->head = new List::Node();
					listok->head->value = currentOb1->value;
					if (temp == nullptr) {
						listok->head->next = listok->tail;
					}
					else {
						listok->head->next = temp;
					}
					listok->Sort();
				}
			}
		}
		if (currentOb2 != nullptr) {
			if (listok->tail == nullptr) {
				listok->tail = new List::Node();
				listok->tail->value = currentOb2->value;
			}
			else {
				if (listok->isSame(currentOb2->value) != true) {
					temp = listok->head;
					listok->head = new List::Node();
					listok->head->value = currentOb2->value;
					if (temp == nullptr) {
						listok->head->next = listok->tail;
					}
					else {
						listok->head->next = temp;
					}
					listok->Sort();
				}
			}
		}
	currentOb1 = currentOb1->next;
	currentOb2 = currentOb2->next;
	}
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
bool operator ==(List& ob, List& ob1) {
	List::Node* currentOb = ob.head;
	List::Node* currentOb1 = ob1.head;
	if (ob.count() != ob1.count()) {
		return false;
	}
	else{
			while ((currentOb != nullptr) && (currentOb1 != nullptr)) {
				if (currentOb->value = currentOb1->value) {
					continue;
				}
				else {
					return false;
					break;
				}
				currentOb = currentOb->next;
				currentOb1 = currentOb1->next;
			}
			return true;
		}
	}
void List::merge(List& ob) {
	Node* currentOb=ob.head;
	while (currentOb != nullptr) {
		Node* temp;
		if (tail == nullptr) {
			tail = new List::Node();
			tail->value = currentOb->value;
		}
		else {
			if (isSame(currentOb->value) != true) {
				temp = head;
				head = new List::Node();
				head->value = currentOb->value;
				if (temp == nullptr) {
					head->next = tail;
				}
				else {
					head->next = temp;
				}
				Sort();
			}
		}
		currentOb = currentOb->next;
	}
}
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
	Node* temp;
	Node* current=ob.head;
	tail = new Node();
	tail->value = current->value;
	current = current->next;
	while (current != nullptr) {
		if (head != nullptr) {
			temp = head;
			head = new Node();
			head->value = current->value;
			head->next = temp;
			current = current->next;
		}
		else {
			head = new Node();
			head->next = tail;
			head->value = current->value;
			current = current->next;
		}
		this->Sort();
	}
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
List& List::operator =(List& obj) {
	deleteList();
	if (obj.head == nullptr)
		return *this;
	head = new Node();
	head->value = obj.head->value;
	Node* currentObj;
	currentObj = obj.head->next;
	Node* current;
	current = head;
	while (currentObj != nullptr)
	{
		Node* Element = new Node();
		Element->value = currentObj->value;
		current->next = Element;
		current = current->next;
		currentObj = currentObj->next;
	}
	return *this;
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
