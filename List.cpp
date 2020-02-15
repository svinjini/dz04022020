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
        if ((currentOb1 != nullptr) && (ob2.isSame(currentOb1->value))) {
            List::Node* temp;
            if (listok->head == nullptr) {
                listok->head = new List::Node(currentOb1->value);
            }
            else {
                if ( ! listok->isSame(currentOb1->value)) {
                    temp = listok->head;
                    listok->head = new List::Node(currentOb1->value);
                    listok->head->next = temp;
                    listok->Sort();
                }
            }
        }
        if (ob1.isSame(currentOb2->value) && (currentOb2 != nullptr)) {
            List::Node* temp;
            if (listok->head == nullptr) {
                listok->head = new List::Node(currentOb2->value);
            }
            else {
                if (! listok->isSame(currentOb2->value)) {
                    temp = listok->head;
                    listok->head = new List::Node(currentOb2->value);
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
            listok->head = new List::Node(currentOb1->value);
        }
        else {
            if ( ! listok->isSame(currentOb1->value)) {
                temp = listok->head;
                listok->head = new List::Node(currentOb1->value);
                listok->head->next = temp;
                listok->Sort();
            }
        }
        if (! listok->isSame(currentOb2->value)) {
            temp = listok->head;
            listok->head = new List::Node(currentOb2->value);
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
            out << " " << current->value;
            current = current->next;
        }
        out << std::endl << std::endl;
        return out;
    }
    else {
        out << "List is empty";
        return out;
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
            if (currentOb->value == currentOb1->value) {
                continue;
            }
            else {
                return false;
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
            head = new Node(currentOb->value);
        }
        else {
            if (! isSame(currentOb->value)) {
                temp = head;
                head = new Node(currentOb->value);
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
        head = new Node(x);
    }
    else {
        if ( ! isSame(x)) {
            temp = head;
            head = new Node(x);
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
    if (ob.head == nullptr) {
        head = nullptr;
    } else {
        head = new Node(ob.head->value);
        Node *current = head;
        Node *obHead = ob.head;
        Node *currentOb = obHead;
        while (currentOb->next != nullptr) {
            current->next = new Node(currentOb->next->value);
            currentOb = currentOb->next;
            current = current->next;
        }
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
    head = new Node(obj.head->value);
    Node* currentObj;
    currentObj = obj.head->next;
    Node* current;
    current = head;
    while (currentObj != nullptr)
    {
        Node* Element = new Node(currentObj->value);
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
            }
            current = current->next;
        }
        return false;
    }
    else {
        return false;
    }
}

List::List(List&& ob) {
    head = ob.head;
    ob.head = nullptr;
}

List::~List() {
    deleteList();
}

