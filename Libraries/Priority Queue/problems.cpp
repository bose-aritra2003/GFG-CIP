# include <iostream>
# include <queue>
# include <unordered_map>

using namespace std;

void sortArray_MaxHeap(vector<int>& arr) {
    /**
     * Time Complexity: O(n log n)
     * Space Complexity: O(n)
     */
    priority_queue<int> pq(arr.begin(), arr.end());
    for(int i = arr.size() - 1; i >= 0; i--) {
        arr[i] = pq.top();
        pq.pop();
    }
}

void sortArray_MinHeap(vector<int>& arr) {
    /**
     * Time Complexity: O(n log n)
     * Space Complexity: O(n)
     */
    priority_queue<int, vector<int>, greater<int>> pq(arr.begin(), arr.end());
    for(int i = 0; i < arr.size(); i++) {
        arr[i] = pq.top();
        pq.pop();
    }
}

vector<int> largestKElements(vector<int>& arr, int k) {
    /**
     * Time Complexity: O(k log n)
     * Space Complexity: O(n)
     */
    priority_queue<int> pq(arr.begin(), arr.end());
    vector<int> res;
    for(int i = 0; i < k; i++) {
        res.push_back(pq.top());
        pq.pop();
    }
    return res;
}

vector<int> optimisedLargestKElements(vector<int>& arr, int k) {
    /**
     * STEP 1: Build a min heap of first k items
     * STEP 2: Traverse from (k+1)th element :
     *          (a) Compare current element with top of heap, if smaller tha top ignore it
     *          (b) Else remove the top element and insert the current element in the min heap
     * STEP 3: Print contents of Min Heap
     *
     * Time Complexity: O(n log k)
     * Space Complexity: O(k)
     */
    priority_queue<int, vector<int>, greater<int>> pq(arr.begin(), arr.begin() + k);
    vector<int> res;
    for(int i = k; i < arr.size(); i++) {
        if(arr[i] > pq.top()) {
            pq.pop();
            pq.push(arr[i]);
        }
    }
    while(!pq.empty()) {
        res.push_back(pq.top());
        pq.pop();
    }
    return res;
}

int maxPurchasesPossible(vector<int>& arr, int money) {
    /**
     * Time Complexity: O(count log n) here we took count, however upper bound is obviously n, but most of the time
     *                  count will be less than n and thus this is more optimised and naive method of sorting and finding.
     * Space Complexity: O(n)
     */
    priority_queue<int, vector<int>, greater<int>> pq(arr.begin(), arr.end());
    int count = 0;
    while(!pq.empty() && money >= pq.top()) {
        money -= pq.top();
        pq.pop();
        count++;
    }
    return count;
}

struct myCmp {
    bool operator()(pair<int, int> a, pair<int, int> b) {
        if(a.second == b.second)
            return a.first > b.first;
        return a.second < b.second;
    }
};

vector<int> kMostFrequentElementsSorted(vector<int>& arr, int k) {
    /**
     * Time Complexity: O(k log n)
     * Space Complexity: O(n)
     */
    unordered_map<int, int> mp;
    for(int &i : arr)
        mp[i]++;
    priority_queue<pair<int, int>, vector<pair<int, int>>, myCmp> pq(mp.begin(), mp.end());
    vector<int> res;
    while(!pq.empty() and res.size() < k) {
        res.push_back(pq.top().first);
        pq.pop();
    }
    return res;
}

vector<int> kMostFrequentElementsLinearTime(vector<int>& arr, int k) {
    /**
     * Time Complexity: O(n)
     * Space Complexity: O(n)
     *
     * The difference here is that here even if we have 2 or more items with the same frequency,
     * we need not necessarily store it in sorted order.
     */
    unordered_map<int, int> mp;
    for(int &i : arr)
        mp[i]++;
    vector<int> freq[arr.size() + 1];
    for(auto &i : mp)
        freq[i.second].push_back(i.first);
    vector<int> res;
    for(int i = arr.size(); i >= 0; i--) {
        for(int j : freq[i]) {
            res.push_back(j);
            if(res.size() == k)
                return res;
        }
    }
    return res;
}

vector<int> kMostFrequentElementsLinearTimeInOrderOfInput(vector<int>& arr, int k) {
    /**
     * Time Complexity: O(n)
     * Space Complexity: O(n)
     *
     * Same as previous question but here if we have two or more elements with same frequency,
     * then we need to print them in order they were present in the input.
     */
    unordered_map<int, int> mp;
    for(int &i : arr)
        mp[i]++;
    vector<int> freq[arr.size() + 1];
    for(int &i : arr) {
        int f = mp[i];
        if(f != -1) {
            freq[f].push_back(i);
            mp[i] = -1;
        }
    }
    vector<int> res;
    for(int i = arr.size(); i >= 0; i--) {
        for(int j : freq[i]) {
            res.push_back(j);
            if(res.size() == k)
                return res;
        }
    }
    return res;
}

int main() {
    vector<int> arr = {3, 6, 1, 2, 8, 9, 5, 7, 4};
    sortArray_MaxHeap(arr);
    for(int i : arr) {
        cout << i << " ";
    }
    return 0;
}
