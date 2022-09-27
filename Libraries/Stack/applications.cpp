# include <iostream>
# include <stack>
# include <vector>

using namespace std;

string reverseString(const string& str) {
    stack<char> s;
    string rev_str;
    for(char i : str) {
        s.push(i);
    }
    for(int i = 0; i < str.length(); i++) {
        rev_str.push_back(s.top());
        s.pop();
    }
    return rev_str;
}

bool validParenthesis(const string &s) {
    /**
     * To check if the parenthesis in a string are valid or not
     */
    stack<char> st;
    for(char i : s) {
        if(i == '(' || i == '{' || i == '[') {
            st.push(i);
        }
        else {
            if(st.empty()) {
                return false;
            }
            char top = st.top();
            st.pop();
            if(i == ')' && top != '(') {
                return false;
            }
            else if(i == '}' && top != '{') {
                return false;
            }
            else if(i == ']' && top != '[') {
                return false;
            }
        }
    }
    return st.empty();
}

vector<int> stockSpan(vector<int> arr) {
    /**
     * Span of a stock on a day is the number of consecutive days before the day on which the stock price
     * was lower than the current day or equal.
     *
     * For example, if the stock price is {100, 80, 60, 70, 60, 75, 85},
     * then the span values for corresponding 7 days are {1, 1, 1, 2, 1, 4, 6}
     *
     * The below solution might look like n^2 but it's actually O(2n) = O(n)
     */
    vector<int> span;
    span.push_back(1);
    stack<int> st;
    st.push(0);
    for(int i = 1; i < arr.size(); i++) {
        while(!st.empty() and arr[st.top()] <= arr[i]) {
            st.pop();
        }
        int span_val = st.empty() ? (i + 1) : (i - st.top());
        span.push_back(span_val);
        st.push(i);
    }
    return span;
}

vector<int> previousClosestGreater(vector<int> arr) {
    /**
     * Given an array of integers, find the closest greater element on the left side of each element.
     * If an element has no greater element on the left side, then print -1.
     *
     * For example, if the given array is {1, 3, 0, 2, 5}, then the output should be {-1, -1, 3, 3, -1}
     *
     * The below solution might look like n^2 but it's actually O(2n) = O(n)
     */
    vector<int> pcg;
    pcg.push_back(-1);
    stack<int> st;
    st.push(arr[0]);
    for(int &i : arr) {
        while(!st.empty() and st.top() <= i) {
            st.pop();
        }
        int pg = (st.empty()) ? -1 : st.top();
        pcg.push_back(pg);
        st.push(i);
    }
    return pcg;
}

vector<int> nextClosestGreater(vector<int> arr) {
    /**
     * Given an array of integers, find the closest greater element on the right side of each element.
     * If an element has no greater element on the right side, then print -1.
     *
     * For example, if the given array is {1, 3, 0, 2, 5}, then the output should be {3, 5, 2, 5, -1}
     *
     * The below solution might look like n^2 but it's actually O(2n) = O(n)
     */
    vector<int> ncg;
    ncg.push_back(-1);
    stack<int> st;
    st.push(arr[arr.size() - 1]);
    for(int i = arr.size() - 2; i >= 0; i--) {
        while(!st.empty() and st.top() <= arr[i]) {
            st.pop();
        }
        int ng = (st.empty()) ? -1 : st.top();
        ncg.push_back(ng);
        st.push(arr[i]);
    }
    reverse(ncg.begin(), ncg.end());
    return ncg;
}

int main() {
    string str = "Hello World";
    cout << reverseString(str) << endl;

    string s1 = "({[]})", s2 = "({[}])";
    cout << validParenthesis(s1) << ' ' << validParenthesis(s2) << endl;

    vector<int> arr = {100, 80, 60, 70, 60, 75, 85};
    vector<int> ans = stockSpan(arr);
    for(int i : ans) {
        cout << i << ' ';
    }
    cout << endl;
    vector<int> arr2 = {20, 30, 10, 5, 15};
    vector<int> ans2 = previousClosestGreater(arr2);
    for(int i : ans2) {
        cout << i << ' ';
    }
    return 0;
}
