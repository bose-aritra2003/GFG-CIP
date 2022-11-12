#include <iostream>
#include <vector>
#include <numeric>
#include <unordered_map>

using namespace std;

// The Thief Problem
int theifProblem(vector<int>& v, int k) {
    sort(v.begin(), v.end(), greater<int>());
    int sum = accumulate(v.begin(), v.begin() + k, 0);
    return sum;
}

// Fractional Knapsack
bool myCmp(pair<int, int> a, pair<int, int> b) {
    double r1 = (double)a.first/a.second;
    double r2 = (double)b.first/b.second;
    return r1 > r2;
}
double fractionalKnapsack(vector<pair<int, int>>& v, int capacity) {
    /**
     * Data is given as: (value, weight) pair
     *
     * Time complexity: O(n log n)
     * Space complexity: O(1) can be done very easily if we don't try to use some STL used below
     */
    int n = v.size();
    sort(v.begin(), v.end(), myCmp);
    vector<int> prefix(n, 0);
    prefix[0] = v[0].second;
    for(int i = 1; i < n; i++) {
        prefix[i] = v[i].second + prefix[i-1];
    }
    int valid_idx = upper_bound(prefix.begin(), prefix.end(), capacity) - prefix.begin();
    int considerable = prefix[valid_idx - 1];
    double extra = 0;
    if(valid_idx < n) {
        extra = ((capacity - considerable) * v[valid_idx].first)/(double)v[valid_idx].second;
    }
    vector<int> values(n);
    for(int i = 0; i < n; i++) {
        values[i] = v[i].first;
    }
    double sum = accumulate(values.begin(), values.begin() + valid_idx, extra);
    return sum;
}

// Chocolate Distribution Problem
int chocolateDistribute(vector<int>& packets, int children) {
    /**
     * Every child should get exactly one packet
     * We need to ensure that the difference of max and min chocolate packets selected is minimum
     *
     * Time complexity: O(n log n)
     */
     int n = packets.size();
     if(children > n) {
         return -1;
     }
     sort(packets.begin(), packets.begin());
     int i = 0, j = children - 1;
     int ans = INT_MAX;
     while(j != n) {
         ans = min(ans, packets[j] - packets[i]);
         i++;
         j++;
     }
     return ans;
}

// Sort array elements by frequency
bool myComp(pair<int, int> a, pair<int, int> b) {
    if(a.second == b.second)  {
        return a.first < b.first;
    }
    return a.second > b.second;
}
void frequencySort(vector<int>& v) {
    /**
     * If two items have the same frequency then put smaller value first
     *
     * Time complexity: O(n log n)
     */
     unordered_map<int, int> mp;
     for(auto &i: v) {
         mp[i]++;
     }
     vector<pair<int, int>> arr(mp.begin(), mp.end());
     sort(arr.begin(), arr.end(), myComp);
     int i = 0;
     for(auto &j: arr) {
         for(int k = 0; k < j.second; k++) {
             v[i++] = j.first;
         }
     }
}
void stableLinearTimeFrequencySort(vector<int>& v) {
    /**
     * Consider only non-negative elements are there in the array
     * Sorting should be such that if there is a tie in the frequency then element that appears first should be present first
     *
     * Time complexity: O(n)
     */
    int n = v.size();
    unordered_map<int, int> mp;
    for(auto &i: v) {
        mp[i]++;
    }
    vector<vector<int>> freq(n + 1, vector<int>());

    // Below commented out code doesn't handle ties
//    for(auto &i: mp) {
//        freq[i.second].push_back(i.first);
//    }

    //Handling ties
    for(int i = 0; i < n; i++) {
        int f = mp[v[i]];
        if(f != -1) {
            freq[f].push_back(v[i]);
            mp[f] = -1;
        }
    }

    int idx = 0;
    for(int i = n; i >= 0; i--) {
        if(!freq[i].empty()) {
            for(auto &j: freq[i]) {
                for(int k = 0; k < i; k++) {
                    v[idx++] = j;
                }
            }
        }
    }
}

int main() {
    vector<pair<int, int>> v = {
            {120, 30},
            {100, 20},
            {60, 10}
    };
    cout << fractionalKnapsack(v, 50);
}