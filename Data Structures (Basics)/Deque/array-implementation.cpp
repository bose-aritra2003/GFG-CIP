#include <iostream>

using namespace std;

class StaticDeque {
private:
    int *arr;
    int front;
    int capacity;
    int size;
public:
    StaticDeque(int cap): front(0), capacity(cap), size(0) {
        arr = new int[cap];
    }
    ~StaticDeque() {
        delete[] arr;
    }
    int getSize() {
        return size;
    }
    bool isEmpty() {
        return size == 0;
    }
    bool isFull() {
        return size == capacity;
    }
    void popFront() {
        if(isEmpty()) {
            return;
        }
        front = (front + 1) % capacity;
        size--;
    }
    void pushBack(int val) {
        if(isFull()) {
            return;
        }
        int new_rear = (front + size) % capacity;
        arr[new_rear] = val;
        size++;
    }
    int getFront() {
        if(isEmpty()) {
            return -1;
        }
        return arr[front];
    }
    void pushFront(int val) {
        if(isFull()) {
            return;
        }
        front = (front - 1 + capacity) % capacity;
        arr[front] = val;
        size++;
    }
    void popBack() {
        if(isEmpty()) {
            return;
        }
        size--;
    }
    int getRear() {
        if(isEmpty()) {
            return -1;
        }
        int new_rear = (front + size - 1) % capacity;
        return arr[new_rear];
    }

};

int main() {
    return 0;
}