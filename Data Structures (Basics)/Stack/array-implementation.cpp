#include <iostream>
#include <vector>

using namespace std;

class StaticStack {
private:
    int *arr;
    int capacity;
    int top;
public:
    StaticStack(int cap = 0): capacity(cap), top(-1) {
        arr = new int[cap];
    }
    int size() {
        return top + 1;
    }
    bool isEmpty() {
        if(top == -1) {
            return true;
        }
        else {
            return false;
        }
    }
    void push(int x) {
        if(top < capacity - 1) {
            top++;
            arr[top] = x;
        }
        else {
            cerr << "Overflow";
        }
    }
    int pop() {
        if(top > -1) {
            int val = arr[top];
            top--;
            return val;
        }
        else {
            cerr << "Underflow";
            return INT_MIN;
        }
    }
    int peek() {
        if(top > -1) {
            return arr[top];
        }
        else {
            cerr << "Underflow";
            return INT_MIN;
        }
    }
};

class DynamicStack {
private:
    int *arr;
    int top;
public:
    DynamicStack(): top(-1) {
        arr = (int *)calloc(1, sizeof(int));
    }
    ~DynamicStack() {
        free(arr);
    }
    int size() {
        return top + 1;
    }
    bool isEmpty() {
        if(top == -1) {
            return true;
        }
        else {
            return false;
        }
    }
    void push(int x) {
        top++;
        arr = (int *)realloc(arr, (top + 1) * sizeof(int));
        arr[top] = x;
    }
    int pop() {
        if(top > -1) {
            int val = arr[top];
            top--;
            arr = (int *)realloc(arr, (top + 1) * sizeof(int));
            return val;
        }
        else {
            cerr << "Underflow";
            return INT_MIN;
        }
    }
    int peek() {
        if(top > -1) {
            return arr[top];
        }
        else {
            cerr << "Underflow";
            return INT_MIN;
        }
    }
};


int main() {
    DynamicStack s;
    s.push(1);
    s.push(2);
    s.push(3);
    cout << s.pop() << endl;
    cout << s.isEmpty() << endl;
    cout << s.size() << endl;
    s.push(6);
    cout << s.peek() << endl;
    cout << s.pop() << endl;
    return 0;
}