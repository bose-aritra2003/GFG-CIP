# include <iostream>
# include <vector>

using namespace std;

class BinaryIndexedTree {
private:
    vector<int> tree;
    vector<int> arr;
    int n;
public:
    explicit BinaryIndexedTree(vector<int> &arr) {
        this->arr = arr;
        this->n = arr.size();
        tree.resize(n + 1);
        for(int i = 0; i < n; i++) {
            update(i, arr[i]);
        }
    }
    int getSum(int i) {
        /**
         * Time Complexity: O(log n)
         */
        i = i + 1;
        int res = 0;
        while (i > 0) {
            res += tree[i];
            i -= i & (-i);
        }
    }
    void update(int i, int val) {
        /**
         * Time Complexity: O(log n)
         */
        int diff = val - arr[i];
        arr[i] = val;
        i = i + 1;
        while (i <= n) {
            tree[i] += diff;
            i += i & (-i);
        }
    }
};