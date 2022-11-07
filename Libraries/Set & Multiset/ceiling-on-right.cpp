#include <iostream>
#include <vector>
#include <set>

using namespace std;

vector<int> ceilingOnRight(vector<int> arr) {
    /**
     * Time complexity: O(n log n)
     * Auxiliary space: O(n)
     */
    int n = arr.size();
    set<int> s;
    vector<int> res(n);
    for(int i = n - 1; i >= 0; i--) {
        auto it = s.lower_bound(arr[i]);
        res[i] = (it == s.end()) ? -1 : *it;
        s.insert(arr[i]);
    }
    return res;
}

int main() {
    vector<int> arr = {100, 50, 30, 60, 55, 32};
    vector<int> res = ceilingOnRight(arr);
    for(int i : res) {
        cout << i << " ";
    }
}