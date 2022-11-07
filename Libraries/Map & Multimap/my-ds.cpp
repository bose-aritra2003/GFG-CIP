// Design a data structure for item prices

/*
 * We need to support the following operations
 * add(price, item)
 * find(price)
 * printSorted()
 * printGreaterSorted(price)
 * printSmallerSorted(price)
 */

#include <iostream>
#include <map>
#include <vector>

using namespace std;

class MyDS {
    /**
     * From the below implementation, we can see that the time complexity of any operation never exceeds O(n).
     */
private:
    multimap<int, string> mp;
public:
    void add(int price, string& item) {
        /*
         * Time complexity: O(log n)
         */
        mp.insert({price, item});
    }
    vector<string> find(int price) {
        /*
         * Time complexity: O(log n)
         */
        vector<string> res;
        if(mp.find(price) != mp.end()) {
            auto itr = mp.equal_range(price);
            for(auto it = itr.first; it != itr.second; it++) {
                res.push_back(it->second);
            }
            return res;
        }
        return res;
    }
    void printSorted() {
        /*
         * Time complexity: O(n)
         */
        for(auto & it : mp) {
            cout << it.first << " " << it.second << endl;
        }
    }
    void printGreaterSorted(int price) {
        /*
         * Time complexity: O(n)
         */
        for(auto it = mp.upper_bound(price); it != mp.end(); it++) {
            cout << it->first << " " << it->second << endl;
        }
    }
    void printSmallerSorted(int price) {
        /*
         * Time complexity: O(n)
         */
        for(auto it = mp.begin(); it != mp.lower_bound(price); it++) {
            cout << it->first << " " << it->second << endl;
        }
    }
};

int main() {

}