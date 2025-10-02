#include <iostream>
using namespace std;

// Node structure
struct Node {
    int data;
    Node* next;
    
    // Constructor
    Node(int val) {
        data = val;
        next = nullptr;
    }
};

// Linked List class
class LinkedList {
private:
    Node* head;

public:
    // Constructor
    LinkedList() {
        head = nullptr;
    }
    
    // Add node at the end
    void insert(int data) {
        Node* newNode = new Node(data);
        
        if (head == nullptr) {
            head = newNode;
        } else {
            Node* temp = head;
            while (temp->next != nullptr) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }
    
    // Add node at beginning
    void insertAtHead(int data) {
        Node* newNode = new Node(data);
        newNode->next = head;
        head = newNode;
    }
    
    // Delete node by value
    void deleteNode(int data) {
        if (head == nullptr) return;
        
        // If head needs to be deleted
        if (head->data == data) {
            Node* temp = head;
            head = head->next;
            delete temp;
            return;
        }
        
        // Search for node to delete
        Node* temp = head;
        while (temp->next != nullptr && temp->next->data != data) {
            temp = temp->next;
        }
        
        // If node found, delete it
        if (temp->next != nullptr) {
            Node* nodeToDelete = temp->next;
            temp->next = temp->next->next;
            delete nodeToDelete;
        }
    }
    
    // Search for a value
    bool search(int data) {
        Node* temp = head;
        while (temp != nullptr) {
            if (temp->data == data) {
                return true;
            }
            temp = temp->next;
        }
        return false;
    }
    
    // Display the list
    void display() {
        Node* temp = head;
        while (temp != nullptr) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }
    
    // Get length of list
    int length() {
        int count = 0;
        Node* temp = head;
        while (temp != nullptr) {
            count++;
            temp = temp->next;
        }
        return count;
    }
};

// Main function to test the linked list
int main() {
    LinkedList list;
    
    // Insert elements
    list.insert(10);
    list.insert(20);
    list.insert(30);
    list.insertAtHead(5);
    
    cout << "Linked List: ";
    list.display();
    
    cout << "Length: " << list.length() << endl;
    
    // Search for elements
    cout << "Search 20: " << (list.search(20) ? "Found" : "Not Found") << endl;
    cout << "Search 25: " << (list.search(25) ? "Found" : "Not Found") << endl;
    
    // Delete elements
    list.deleteNode(20);
    cout << "After deleting 20: ";
    list.display();
    
    list.deleteNode(5);
    cout << "After deleting 5: ";
    list.display();
    
    return 0;
}


// output ->
/*
Linked List: 5 -> 10 -> 20 -> 30 -> NULL
Length: 4
Search 20: Found
Search 25: Not Found
After deleting 20: 5 -> 10 -> 30 -> NULL
After deleting 5: 10 -> 30 -> NULL
*/