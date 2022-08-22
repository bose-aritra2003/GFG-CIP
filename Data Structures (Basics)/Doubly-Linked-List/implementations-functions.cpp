#include <iostream>

using namespace std;

struct Node {
    int data;
    Node *prev;
    Node *next;
    Node(int x) {
        data = x;
        prev = nullptr;
        next = nullptr;
    }
};

void printDoublyList(Node *head) {
    /**
     * Prints the doubly linked list
     * Time Complexity: O(n)
     * Auxiliary Space: O(1)
     */
    Node *temp = head;
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

Node* insertAtBeginning(Node *head, int x) {
    /**
     * Inserts a node at the beginning of the list.
     * Time Complexity: O(1)
     * Auxiliary Space: O(1)
     */
    Node* newNode = new Node(x);
    newNode->next = head;
    if(head != nullptr) {
        head->prev = newNode;
    }
    return newNode;
}

Node* insertAtEnd(Node *head, int x) {
    /**
     * Insert at end of a doubly linked list
     * Time Complexity: O(n)
     * Auxiliary Space: O(1)
     */
    Node* newNode = new Node(x);
    if(head == nullptr) {
        return newNode;
    }
    Node *curr = head;
    while(curr->next != nullptr) {
        curr = curr->next;
    }
    curr->next = newNode;
    newNode->prev = curr;
    return head;
}

Node* reverseADoublyLinkedList(Node *head) {
    /**
     * Reverse a doubly linked list
     * Time Complexity: O(n)
     * Auxiliary Space: O(1)
     */
    if(head == nullptr or head->next == nullptr) {
        return head;
    }
    Node *curr = head;
    Node *temp = nullptr;
    while(curr != nullptr) {
        temp = curr->prev;
        curr->prev = curr->next;
        curr->next = temp;
        curr = curr->prev;
    }
    return temp->prev;
}

Node* deleteHead(Node *head) {
    /**
     * Delete the head of a doubly linked list
     * Time Complexity: O(1)
     * Auxiliary Space: O(1)
     */
    if(head == nullptr) {
        return nullptr;
    }
    if(head->next == nullptr) {
        delete head;
        return nullptr;
    }
    Node *temp = head;
    head = head->next;
    head->prev = nullptr;
    delete temp;
    return head;
}

Node* deleteLastNode(Node *head) {
    /**
     * Delete the last node of a doubly linked list
     * Time Complexity: O(n)
     * Auxiliary Space: O(1)
     */
    if(head == nullptr) {
        return nullptr;
    }
    if(head->next == nullptr) {
        delete head;
        return nullptr;
    }
    Node *curr = head;
    while(curr->next != nullptr) {
        curr = curr->next;
    }
    delete curr->next;
    curr->next = nullptr;
    return head;
}

int main() {
    Node *head = new Node(10);
    Node *temp1 = new Node(20);
    Node *temp2 = new Node(30);
    head->next = temp1;
    temp1->prev = head;
    temp1->next = temp2;
    temp2->prev = temp1;
    printDoublyList(deleteLastNode(head));
}