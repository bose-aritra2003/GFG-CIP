#include <iostream>

using namespace std;

class StaticQueue {
private:
    int *arr;
    int front, capacity, sz;
public:
    StaticQueue(int cap): capacity(cap), front(0), sz(0) {
        arr = new int[cap];
    }
    int size() {
        return sz;
    }
    bool isFull() {
        return sz == capacity;
    }
    bool isEmpty() {
        return sz == 0;
    }
    int getFront() {
        if(isEmpty()) {
            cerr << "Underflow";
            return INT_MIN;
        }
        else{
            return arr[front];
        }
    }
    int getRear() {
        if(isEmpty()) {
            cerr << "Underflow";
            return INT_MIN;
        }
        else{
            return arr[(front + sz - 1) % capacity];
        }
    }
    void enqueue(int x) {
        if(isFull()) {
            cerr << "Overflow";
        }
        else{
            int rear = (isEmpty()) ? -1 : (front + sz - 1) % capacity;
            rear = (rear + 1) % capacity;
            arr[rear] = x;
            sz++;
        }
    }
    int dequeue() {
        if(isEmpty()) {
            cerr << "Underflow";
            return INT_MIN;
        }
        else{
            int x = arr[front];
            front = (front + 1) % capacity;
            sz--;
            return x;
        }
    }

};

int main() {
    StaticQueue q(5);
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    cout << q.getFront() << endl;
    cout << q.getRear() << endl;
    q.dequeue();
    cout << q.getFront() << endl;
    cout << q.size() << endl;
    cout << q.isFull() << endl;
    cout << q.isEmpty() << endl;
    return 0;
}