#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

void rearrangeTwoSortedArrays(vector<int>& a, vector<int>& b) {
    /**
     * Examples:
     *
     * input: a = {3, 20, 40}
     *        b = {2, 10, 12}
     *
     * output: a = {2, 3, 10}
     *         b = {12, 20, 40}
     *
     * Time complexity: O(n log m + m log m) = O((n + m) log m)
     * Auxiliary space: O(1)
     */
    int n = a.size(), m = b.size();
    make_heap(b.begin(), b.end(), greater<int>());
    for(int i = 0; i < n; i++) {
        if(a[i] > b[0]) {
            pop_heap(b.begin(), b.end(), greater<int>());
            swap(a[i], b[m-1]);
            push_heap(b.begin(), b.end(), greater<int>());
        }
    }
    sort_heap(b.begin(), b.end());
    //Although you can also use just "sort()" at the end but since b is already a heap, sort_heap() is more optimised
}