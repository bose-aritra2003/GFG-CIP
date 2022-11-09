#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

string winnerOfElection(vector<string>& arr) {
    /**
     * The one whose name occurs maximum number of times is the winner
     * If there are multiple winners the one whose name is lexicographically smaller will be the winner
     *
     * Time complexity: O(n * max_len)
     */
    unordered_map<string, int> mp;
    for(auto &i: arr) {
        mp[i]++;
    }
    int max_votes = 0;
    string winner;
    for(auto &i: mp) {
        if(i.second > max_votes) {
            max_votes = i.second;
            winner = i.first;
        }
        else if(i.second == max_votes and i.first < winner) {
            winner = i.first;
        }
    }
    return winner;
}