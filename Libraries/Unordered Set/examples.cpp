#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

vector<int> distinctElements(vector<int>& arr) {
    /**
     * Time complexity: O(n)
     * Auxiliary space: O(n)
     */
    unordered_set<int> s;
    vector<int> ans;
    for(int & i : arr) {
        if(s.find(i) == s.end()) {
            s.insert(i);
            ans.push_back(i);
        }
    }
    return ans;
}

vector<int> repeatingElements(vector<int>& arr) {
    /**
     * Time Complexity: O(n)
     * Auxiliary Space: O(n)
     */
    unordered_set<int> s;
    vector<int> ans;
    for(int & i : arr) {
        if(s.find(i) == s.end()) {
            s.insert(i);
        } else {
            ans.push_back(i);
        }
    }
    return ans;
}

int maximiseDistinctElementsInASubset(vector<int>& v, int k) {
    int count = v.size()/k;
    unordered_set<int> s;
    for(int & i : v) {
        s.insert(i);
    }
    int d = s.size();
    return min(d, count);
}

int main() {

}