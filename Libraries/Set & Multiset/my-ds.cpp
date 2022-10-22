//Design a data structure with floor and ceiling

/*
 * We need to support the following operations:
 * searchVal(x)
 * insertVal(x)
 * deleteVal(x)
 * getFloor(x): Largest value smaller than or equal to x (otherwise INT_MIN)
 * getCeiling(x): Smallest value greater than or equal to x (otherwise INT_MAX)
 */

#include <iostream>
#include <set>

using namespace std;

class MyDS {
    /**
     * From the below implementation, we can see that the time complexity of any operation never exceeds O(log n).
     * Instead if we had used an unordered_set, the time complexity of searchVal() would have been O(n).
     */
private:
    set<int> s;
public:
    bool searchVal(int x) {
        if(s.find(x) != s.end()) {
            return true;
        }
        else {
           return false;
        }
    }
    void insertVal(int x) {
        s.insert(x);
    }
    void deleteVal(int x) {
        if(searchVal(x)) {
            s.erase(x);
        }
    }
    int getFloor(int x) {
        auto it = s.lower_bound(x);
        if(it == s.end()) {
            return *prev(it);
        }
        else if(it == s.begin()) {
            return (*it == x) ? x : INT_MIN;
        }
        else {
            return (*it == x) ? x : *prev(it);
        }
    }
    int getCeiling(int x) {
        auto it = s.lower_bound(x);
        return (it != s.end()) ? INT_MAX : *it;
    }
};
