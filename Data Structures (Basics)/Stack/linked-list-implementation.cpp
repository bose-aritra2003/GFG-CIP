#include <iostream>
#include <vector>

using namespace std;

struct Node {
    int data;
    Node *next;
    Node(int x) : data(x), next(nullptr) {}
};

class MyStack {
private:
    Node *head;
    int sz;
public:
    MyStack() : head(nullptr), sz(0) {}
    int size() {
        return sz;
    }
    bool isEmpty() {
        if(sz == 0) {
            return true;
        }
        else {
            return false;
        }
    }
    void push(int x) {
        Node *temp = new Node(x);
        temp->next = head;
        head = temp;
        sz++;
    }
    int pop() {
        if(sz == 0) {
            cerr << "Underflow";
            return INT_MIN;
        }
        Node *temp = head;
        int val = temp->data;
        head = head->next;
        sz--;
        delete temp;
        return val;
    }
    int peek() {
        if(sz == 0) {
            cerr << "Underflow";
            return INT_MIN;
        }
        return head->data;
    }
};


int main() {
    MyStack s;
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