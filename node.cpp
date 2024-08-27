#include <iostream>  // Include the standard I/O library

using namespace std;  // Use the standard namespace

// Node structure
class Node {
    public:

    int data;
    Node* next;
    // Constructor
    Node(int value) : data(value), next(nullptr) {}

    // Overloading the new operator
    void* operator new(size_t size) {
        cout << "Custom new operator called\n";
        void* p = std::malloc(size);
        if (!p) {
            throw std::bad_alloc();
        }
        return p;
    }

    // Overloading the delete operator
    void operator delete(void* p) {
        cout << "Custom delete operator called\n";
        std::free(p);
    }

    // Function to print the linked list
    void printList() const {
        const Node* temp = this;
        while (temp != nullptr) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "nullptr" << endl;
    }
};

// Non-member function to overload the + operator (adding a node)
Node* operator+(  Node* head, int value) {
    Node* newNode = new Node(value);
    if (!head) {
        return newNode;
    }
    Node* temp = head;
    while (temp->next != nullptr) {
        temp = temp->next;
    }
    temp->next = newNode;
    return head;
}

// Non-member function to overload the - operator (deleting a node)
Node* operator-(Node* head, int value) {
    if (!head) return nullptr;

    Node* temp = head;
    Node* prev = nullptr;

    // If head node itself holds the value to be deleted
    if (temp != nullptr && temp->data == value) {
        Node* toDelete = temp;
        head = temp->next;
        delete toDelete;
        return head;  // New head after deletion
    }

    // Search for the value to be deleted, keep track of the previous node
    while (temp != nullptr && temp->data != value) {
        prev = temp;
        temp = temp->next;
    }

    // If the value was not found in the list
    if (temp == nullptr) return head;

    // Unlink the node from the list
    prev->next = temp->next;
    delete temp;

    return head;  // Return the head of the list
}

int main() {
    // Creating a linked list with a single node
    Node* head = new Node(1);

    // Adding nodes using overloaded + operator
    head = head + 2;
     head->printList();
    head = head +3;
    //head = head + 4;
    head->printList();  // Output: 1 -> 2 -> 3 -> 4 -> nullptr

    head = head -3;
    head->printList();
    // Deleting a node using overloaded - operator
   // head = head - 3;
     // Output: 1 -> 2 -> 4 -> nullptr

    // Cleanup


    return 0;
}
