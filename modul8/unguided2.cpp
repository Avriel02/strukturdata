#include <iostream>
using namespace std;

struct node {
    string name;
    node *prev;
    node *next;
};

node *compartemen;
node *head;
node *tail;

// Function to insert a new node before a specific node
void insertBefore(string target, string newName) {
    node *newNode = new node;
    newNode->name = newName;

    node *current = head;
    do {
        if (current->name == target) {
            newNode->next = current;
            newNode->prev = current->prev;
            current->prev->next = newNode;
            current->prev = newNode;

            if (current == head) {
                head = newNode;
            }
            return;
        }
        current = current->next;
    } while (current != head);
}

// Function to insert a new node after a specific node
void insertAfter(string target, string newName) {
    node *newNode = new node;
    newNode->name = newName;

    node *current = head;
    do {
        if (current->name == target) {
            newNode->prev = current;
            newNode->next = current->next;
            current->next->prev = newNode;
            current->next = newNode;

            if (current == tail) {
                tail = newNode;
            }
            return;
        }
        current = current->next;
    } while (current != head);
}

// Function to print the list
void printList() {
    if (!head) return;
    node *current = head;
    do {
        cout << current->name << " ";
        current = current->next;
    } while (current != head);
    cout << endl;
}

int main() {
    // Initialize the linked list with one node
    compartemen = new node;
    compartemen->name = "nike";
    compartemen->prev = compartemen;
    compartemen->next = compartemen;
    head = compartemen;
    tail = compartemen;

    // Add data before 'nike'
    compartemen = new node;
    compartemen->name = "adidas";
    compartemen->next = head;
    compartemen->prev = tail;
    tail->next = compartemen;
    head->prev = compartemen;
    head = compartemen;

    // Add data after 'nike'
    compartemen = new node;
    compartemen->name = "puma";
    compartemen->prev = tail;
    compartemen->next = head;
    tail->next = compartemen;
    head->prev = compartemen;
    tail = compartemen;

    // Add data 'larocking' after 'nike'
    insertAfter("nike", "larocking");

    // Print the list
    printList();

    return 0;
}
