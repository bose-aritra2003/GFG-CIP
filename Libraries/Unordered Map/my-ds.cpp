// Design a Data Structure for storing balances

/**
  * Implement following functions:
  * set(user_id, balance): assigns a new user with user_id if not present and if present it just simply updates the balance
  * get(user_id): if present returns the balance of the user who user_id is provided
  */

#include <iostream>
#include <unordered_map>
using namespace std;

class MyDS {
private:
    unordered_map<int, int> mp;
public:
    void set(int user_id, int balance) {
        /**
         * Time complexity: O(1)
         */
        mp[user_id] = balance;
    }
    int get(int user_id) {
        /**
         * Time complexity: O(1)
         */
        return (mp.find(user_id) != mp.end()) ? mp[user_id] : -1;
    }
};