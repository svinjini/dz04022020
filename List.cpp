#include "List.h"


List::List()
{
	head = nullptr;
}
List& operator &(List& ob1, List& ob2) {
	List* listok = new List();
	List::Node* currentOb1 = ob1.head;
	List::Node* currentOb2 = ob2.head;
	while ((currentOb1 != nullptr) || (currentOb2 != nullptr)) {
		if ((currentOb1 != nullptr) && (ob2.isSame(currentOb1->value) == true)) {
			List::Node* temp;
			if (listok->head == nullptr) {
				listok->head = new List::Node();
				listok->head->value = currentOb1->value;
			}
			else {
				if (listok->isSame(currentOb1->value) != true) {
					temp = listok->head;
					listok->head = new List::Node();
					listok->head->value = currentOb1->value;
					listok->head->next = temp;
					listok->Sort();
				}
			}
		}
		if ((ob1.isSame(currentOb2->value) == true) && (currentOb2 != nullptr)) {
			List::Node* temp;
			if (listok->head == nullptr) {
				listok->head = new List::Node();
				listok->head->value = currentOb2->value;
			}
			else {
				if (listok->isSame(currentOb2->value) != true) {
					temp = listok->head;
					listok->head = new List::Node();
					listok->head->value = currentOb2->value;
					listok->head->next = temp;
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
	int x = 0;
	Node* current = head;
	while (current != nullptr) {
		x++;
		current = current->next;
	}
	return x;
}
List& operator |(List& ob1, List& ob2) {
	List* listok = new List();
	List::Node* currentOb1 = ob1.head;
	List::Node* currentOb2 = ob2.head;
	while ((currentOb1 != nullptr) || (currentOb2 != nullptr)) {
		List::Node* temp;
		if (listok->head == nullptr) {
			listok->head = new List::Node();
			listok->head->value = currentOb1->value;
		}
		else {
			if (listok->isSame(currentOb1->value) != true) {
				temp = listok->head;
				listok->head = new List::Node();
				listok->head->value = currentOb1->value;
				listok->head->next = temp;
				listok->Sort();
			}
		}
		if (listok->isSame(currentOb2->value) != true) {
			temp = listok->head;
			listok->head = new List::Node();
			listok->head->value = currentOb2->value;
			listok->head->next = temp;
			listok->Sort();
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
			out << current->value << std::endl;
			current = current->next;
		}
		return out;
	}
	else {
		out << "NO DATA!";
	}
}
bool operator ==(List& ob, List& ob1) {
	List::Node* currentOb = ob.head;
	List::Node* currentOb1 = ob1.head;
	if (ob.count() != ob1.count()) {
		return false;
	}
	else {
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
	Node* currentOb = ob.head;
	Node* temp;
	while (currentOb != nullptr) {
		if (head == nullptr) {
			head = new Node();
			head->value = currentOb->value;
		}
		else {
			if (isSame(currentOb->value) != true) {
				temp = head;
				head = new Node();
				head->value = currentOb->value;
				head->next = temp;
				Sort();
			}
		}
		currentOb = currentOb->next;
	}
	ob.deleteList();
}
List& List::operator +=(int x) {
	Node* temp;
	if (head == nullptr) {
		head = new Node();
		head->value = x;
	}
	else {
		if (isSame(x) != true) {
			temp = head;
			head = new Node();
			head->value = x;
			head->next = temp;
			Sort();
		}
	}
	return *this;
}
void List::deleteList() {
	Node* temp=head;
	while (head != nullptr) {
		temp = head->next;
		deleteNode(head);
		head = temp;
	}
}
void List::deleteNode(Node* a) {
	delete a;
}
List::List(const List& ob) {
	Node* temp;
	Node* current = ob.head;
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
			head->value = current->value;
			current = current->next;
		}
		this->Sort();
	}
}
void List::Sort() {
	if (head != nullptr) {
		Node* current = head;
		int x;
		while ((current->next != nullptr) && (current->value > current->next->value)) {
			x = current->value;
			current->value = current->next->value;
			current->next->value = x;
			current = current->next;
		}
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
		std::cerr << "NO DATA!" << std::endl;
	}
}
List::List(List&& ob) {
	deleteList();
	head = ob.head;
	ob.head = nullptr;
}
List::~List()
{


	deleteList();
}
