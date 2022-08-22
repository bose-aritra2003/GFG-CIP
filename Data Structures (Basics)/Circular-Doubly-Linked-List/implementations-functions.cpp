#include <iostream>

using namespace std;

struct Node {
    int data;
    Node *next;
    Node *prev;
    Node(int data) {
        data = data;
        next = nullptr;
        prev = nullptr;
    }
};

Node* insertAtHead(Node *head, int data) {
    Node *newNode = new Node(data);
    if (head == nullptr) {
        newNode->next = newNode;
        newNode->prev = newNode;
    }
    else {
        newNode->prev = head->prev;
        newNode->next = head;
        head->prev->next = newNode;
        head->prev = newNode;
    }
    return newNode;
}

Node* insertAtEnd(Node *head, int data) {
    Node *newNode = new Node(data);
    if (head == nullptr) {
        newNode->next = newNode;
        newNode->prev = newNode;
        return newNode;
    }
    else {
        newNode->prev = head->prev;
        newNode->next = head;
        head->prev->next = newNode;
        head->prev = newNode;
    }
    return head;
}

int main() {
    Node *head = nullptr;
    head = insertAtHead(head, 1);
    head = insertAtHead(head, 2);
    head = insertAtHead(head, 3);
    head = insertAtHead(head, 4);
    return 0;
}