# include <iostream>
# include <stack>
# include <queue>

using namespace std;

void firstKItemsInAQueue(queue<int>& q, int k) {
    /**
     * Time complexity: O(n + k)
     * Space complexity: O(k)
     */
    if(k > q.size()) {
        cout << "Invalid input" << endl;
        return;
    }
    stack<int> s;
    for(int i = 0; i < k; i++) {
        s.push(q.front());
        q.pop();
    }
    while (!s.empty()) {
        q.push(s.top());
        s.pop();
    }
    for(int i = 0; i < q.size() - k; i++) {
        q.push(q.front());
        q.pop();
    }
}

int main() {
    queue<int> q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);
    q.push(6);
    q.push(7);
    q.push(8);
    q.push(9);
    q.push(10);
    firstKItemsInAQueue(q, 5);
    while (!q.empty()) {
        cout << q.front() << " ";
        q.pop();
    }
    return 0;
}
