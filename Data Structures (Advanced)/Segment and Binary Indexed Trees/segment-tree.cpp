# include <iostream>
# include <vector>

using namespace std;

class SegmentTree {
private:
    vector<int> tree;
    vector<int> arr;
    int n;

    int build(int start, int end, int idx) {
        if (start == end) {
            tree[idx] = arr[start];
            return tree[idx];
        }
        int mid = start + (end - start) / 2;
        int leftSum = build(start, mid, 2 * idx + 1);
        int rightSum = build(mid + 1, end, 2 * idx + 2);
        tree[idx] = leftSum + rightSum;
        return tree[idx];
    }
    int getSum(int qs, int qe, int start, int end, int idx) {
        /**
         * Time Complexity: O(log n)
         */
        if (qs > end || qe < start) {
            return 0;
        }
        if (qs <= start && qe >= end) {
            return tree[idx];
        }
        int mid = start + (end - start) / 2;
        int leftSum = getSum(qs, qe, start, mid, 2 * idx + 1);
        int rightSum = getSum(qs, qe, mid + 1, end, 2 * idx + 2);
        return leftSum + rightSum;
    }
    void update(int start, int end, int pos, int idx, int val) {
        /**
         * Time Complexity: O(log n)
         */
        if(pos < start || pos > end) {
            return;
        }
        tree[idx] += val;
        if(start != end) {
            int mid = start + (end - start) / 2;
            update(start, mid, pos, 2 * idx + 1, val);
            update(mid + 1, end, pos, 2 * idx + 2, val);
        }
    }
public:
    explicit SegmentTree(vector<int> &arr) {
        n = arr.size();
        tree.resize(4 * n);
        this->arr = arr;
        build(0, n - 1, 0);
    }
    vector<int> getArray() {
        return arr;
    }
    int rangeQuery(int qs, int qe) {
        return getSum(qs, qe, 0, n - 1, 0);
    }
    void updateQuery(int pos, int val) {
        int diff = val - arr[pos];
        arr[pos] = val;
        update(0, n - 1, pos, 0, diff);
    }
};