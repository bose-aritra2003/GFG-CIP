#include <iostream>

using namespace std;

struct Node {
    int data;
    Node *next;
    Node(int x) {
        data = x;
        next = nullptr;
    }
};

void printCircularList(Node *head) {
    /**
     * Prints the circular list
     * Time Complexity: O(n)
     * Auxiliary Space: O(1)
     */
    if(head == nullptr) {
        return;
    }
    Node *temp = head;
    do {
        cout << temp->data << ' ';
        temp = temp->next;
    } while (temp != head);
}

Node* insertAtBeginning(Node *head, int x) {
    /**
     * Inserts a node at the beginning of the list
     * Time Complexity: O(1)
     * Auxiliary Space: O(1)
     */
    if(head == nullptr) {
        head = new Node(x);
    }
    else {
        Node *newNode = new Node(x);
        newNode->next = head->next;
        head->next = newNode;
        swap(head->data, newNode->data);
    }
    return head;
}

Node* insertAtEnd(Node *head, int x) {
    /**
     * Inserts a node at the end of the list
     * Time Complexity: O(1)
     * Auxiliary Space: O(1)
     */
    Node* newNode = new Node(x);
    if(head == nullptr) {
        newNode->next = newNode;
    }
    else {
        newNode->next = head->next;
        head->next = newNode;
        swap(head->data, newNode->data);
    }
    return newNode;
}

Node* deleteHead(Node *head) {
    /**
     * Deletes the head of the circular list
     * Time Complexity: O(1)
     * Auxiliary Space: O(1)
     */
    if(head == nullptr) {
        return nullptr;
    }
    if(head->next == head) {
        delete head;
        return nullptr;
    }
    head->data = head->next->data;
    Node *temp = head->next;
    head->next = temp->next;
    delete temp;
    return head;
}

Node* deleteKthElement(Node *head, int k) {
    /**
     * Deletes the kth element from the circular list
     * Assumption: k is valid that is k is less than the length of the list
     * Time Complexity: O(n)
     * Auxiliary Space: O(1)
     */
    if(head == nullptr) {
        return nullptr;
    }
    if(k == 1) {
        return deleteHead(head);
    }
    Node *curr = head;
    while(k > 2) {
        curr = curr->next;
        k--;
    }
    Node *temp = curr->next;
    curr->next = temp->next;
    delete temp;
    return head;
}

int main() {
    Node *head = new Node(10);
    head->next = new Node(5);
    head->next->next = new Node(20);
    head->next->next->next = new Node(15);
    head->next->next->next->next = head;
    printCircularList(deleteKthElement(head, 2));
    return 0;
}