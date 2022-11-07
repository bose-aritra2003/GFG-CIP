#include <iostream>
#include <map>
#include <vector>

using namespace std;

vector<int> countGreaterElements(vector<int> arr) {
    /**
     * @return: The number of elements greater than the each element in the array
     * Time Complexity: O(n log n)
     * Auxiliary Space: O(n)
     */
     int n = arr.size();
     map<int, int> mp;
     for(auto &i: arr) {
         mp[i]++;
     }
     int cumulative_freq = 0;
     for(auto it = mp.rbegin(); it != mp.rend(); it++) {
         int freq = it->second;
         it->second = cumulative_freq;
         cumulative_freq += freq;
     }
     vector<int> ans;
     for(int i = 0; i< n; i++) {
         ans.push_back(mp[arr[i]]);
     }
     return ans;
}

int main() {
    vector<int> arr = {2, 8, 10, 5, 8};
    vector<int> ans = countGreaterElements(arr);
    for(auto &i: ans) {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}