#include "List.h"


List::List()
{
    head = nullptr;
}

List& operator &(List& ob1, List& ob2) {
    // create new List
    List* listok = new List();
    List::Node* node = ob1.head;
    // and add values which found in ob1 and ob2
    while (node != nullptr) {
        int value = node->value;
        if (ob2.hasValue(value)) {
            listok->insert(value);
        }
        node = node->next;
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
    List* listok = new List(ob1);
    List::Node* node = ob2.head;
    while (node != nullptr) {
        listok->insert(node->value);
        node = node->next;
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

bool operator !=(List& ob, List& ob1) {
    return !(ob == ob1);
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
                currentOb = currentOb->next;
                currentOb1 = currentOb1->next;
                continue;
            }
            else {
                return false;
            }
        }
        return true;
    }
}

void List::merge(List& ob) {
    List::Node* node = ob.head;
    while (node != nullptr) {
        insert(node->value);
        node = node->next;
    }
    ob.deleteList();
}

List& List::operator +=(int x) {
    insert(x);
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

void List::insert(int x) {
    if (head == nullptr) {
        // inserting first value at head
        head = new Node(x);
        return;
    }
    Node* node = head;
    Node* prev = head;
    while (node != nullptr) {
        if (node->value == x) {
            return; // not inserting duplicate
        }
        if (node->value < x) {
            prev = node;
            node = node->next;
            continue;
        } else {
            if (node == head) {
                // inserting at head
                head = new Node(x);
                head->next = node;
                return;
            }
            // inserting in the middle
            prev->next = new Node(x);
            prev->next->next = node;
            return;
        }
    }
    // inserting at tail
    prev->next = new Node(x);
}

bool List::hasValue(int x) {
    Node* node = head;
    while (node != nullptr) {
        if (node->value == x) {
            return true;
        }
        if (node->value > x) {
            // abort search since list is sorted
            return false;
        }
        node = node->next;
    }
    return false;
}
