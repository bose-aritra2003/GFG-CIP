#include <iostream>

using namespace std;

struct Node {
    int data;
    Node *next;
    Node(int x): data(x), next(nullptr) {}
};

class DynamicQueue {
private:
    Node *front;
    Node *rear;
    int sz;
public:
    DynamicQueue(): front(nullptr), rear(nullptr), sz(0) {}
    int size() { return sz; }
    bool isEmpty() { return sz == 0; }
    int getFront() {
        if (isEmpty()) {
            cerr << "Underflow";
            return INT_MIN;
        }
        else { return front->data; }

    }
    int getRear() {
        if (isEmpty()) {
            cerr << "Underflow";
            return INT_MIN;
        }
        else { return rear->data; }
    }
    void enqueue(int x) {
        Node *new_node = new Node(x);
        if (isEmpty()) {
            front = new_node;
            rear = new_node;
        }
        else {
            rear->next = new_node;
            rear = new_node;
        }
        sz++;
    }
    int dequeue() {
        if (isEmpty()) {
            cerr << "Underflow";
            return INT_MIN;
        }
        else {
            int val = front->data;
            Node *temp = front;
            front = front->next;
            if(front == nullptr) { rear = nullptr; }
            delete temp;
            sz--;
            return val;
        }
    }
};


int main() {
    DynamicQueue q;
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    cout << q.getFront() << endl;
    cout << q.getRear() << endl;
    cout << q.size() << endl;
    cout << q.dequeue() << endl;
    cout << q.dequeue() << endl;
    cout << q.getRear() << endl;
    cout << q.getFront() << endl;
    cout << q.size() << endl;
    return 0;
}