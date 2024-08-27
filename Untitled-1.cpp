#include <iostream>
using namespace std;
class list {
public:
    int data;
    list* next;
    void* operator new(size_t size, int value) {
        return ::operator new(size);
       
    }
    void operator delete(void* ptr, int item) {
        list* list = static_cast<list*>(ptr);
        if (list->data == item) {
            cout << item << " deleted" << endl;
            ::operator delete(ptr);
        } 
        else {
            cout <<" not found" << endl;
        }
    }
};
class LinkedList {
private:
    list* head;
public:
    LinkedList() : head(nullptr) {}
    void addlist(int value) {
        list* newlist = new (value) list; 
        if (head == nullptr) {
            head = newlist
t;
        } 
        else {
            list
t* temp = head;
            while (temp->next != nullptr) {
                temp = temp->next;
            }
            temp->next = newlist
t;
        }
    }
    void deletelist(int value) {
        if (head == nullptr) return;
        if (head->data == value) {
            list
t* temp = head;
            head = head->next;
            delete temp;
            cout << "list
t with value " << value << " deleted from the list." << endl;
            return;
        }
        list* current = head;
        list* prev = nullptr;
        while (current != nullptr && current->data != value) {
            prev = current;
            current = current->next;
        }
        if (current != nullptr) {
            prev->next = current->next;
            delete current;
            cout << "list
t with value " << value << " deleted from the list." << endl;
        }
         else {
            cout << "list
t with value " << value << " not found in the list." << endl;
        }
    }
    void display() {
        list* temp = head;
        while (temp != nullptr) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "nullptr" << endl;
    }
};
LinkedList& operator+(LinkedList& list, int value) {
    list.addlist(value);
    return list;
}
LinkedList& operator-(LinkedList& list, int value) {
    list.deletelist(value);
    return list;
}
int main() {
    list l;
    l = l + 2;  
    l = l - 3;  
    l.display();   
    return 0;
}