#include <iostream>

using namespace std;

struct Node {
    int data;
    Node *next;
    Node *prev;
    Node(int data): data(data), next(nullptr), prev(nullptr) {}
};

class DynamicDeque {
private:
    Node *head;
    Node *tail;
    int size;
public:
    DynamicDeque(): head(nullptr), tail(nullptr), size(0) {}
    int getSize() {
        return size;
    }
    bool isEmpty() {
        return size == 0;
    }
    int getFront() {
        if (isEmpty()) {
            cerr << "Deque is empty";
            return -1;
        }
        return head->data;
    }
    int getBack() {
        if (isEmpty()) {
            cerr << "Deque is empty";
            return -1;
        }
        return tail->data;
    }
    void pushFront(int data) {
        Node *newNode = new Node(data);
        if (isEmpty()) {
            head = newNode;
            tail = newNode;
        } else {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
        size++;
    }
    void pushBack(int data) {
        Node *newNode = new Node(data);
        if (isEmpty()) {
            head = newNode;
            tail = newNode;
        } else {
            newNode->prev = tail;
            tail->next = newNode;
            tail = newNode;
        }
        size++;
    }
    void popFront() {
        if (isEmpty()) {
            cerr << "Underflow";
            return;
        }
        Node *temp = head;
        head = head->next;
        delete temp;
        size--;
    }
    void popBack() {
        if (isEmpty()) {
            cerr << "Underflow";
            return;
        }
        Node *temp = tail;
        tail = tail->prev;
        delete temp;
        size--;
    }
};

int main() {
    return 0;
}