#include <iostream>
#include <vector>
#include <tuple>

using namespace std;

/**
 * Good programming practises with strings:
 * 1. When you pass a string to a function as parameter, pass it by it's address
 * 2. When you are passing a string by address but don't want to modify the string in the function
 *    then use the keyword const before the string data type. This improves readability.
 */

//Search for a pattern in a string and output the position where they are located
void searchPattern(const string &s, const string& pat) {
    int pos = s.find(pat);
    while(pos != string::npos) {
        cout << pos << " ";
        pos = s.find(pat, pos+1);
    }
}

//Digits after decimal point
string digitsAfterDecimalPoint(const string &s) {
    int pos = s.find('.');
    if(pos != string::npos) {
        return s.substr(pos+1);
    }
    return "";
}

//Find the extra character in one of the strings
//Method 1
char extraCharacter1(const string& s1, const string& s2) {
    /**
     * Time complexity: O(n)
     * Auxiliary space: O(256) = O(1)
     */
    vector<int> freq(256, 0);
    int n = s1.length(), m = s2.length(), i = 0, j = 0;

    while(i < n and j < m) {
        freq[s1[i++]]++;
        freq[s2[j++]]--;
    }
    if(i < n) { freq[s1[i]]++; }
    if(j < m) { freq[s2[j]]++; }
    for(int k = 0; k < 256; k++) {
        if(freq[k] != 0) {
            return (char)k;
        }
    }

    return '\0';
}

//Method 2
char extraCharacter2(const string& s1, const string& s2) {
    /**
     * Time complexity: O(n)
     * Auxiliary space: O(1)
     */
    int n = s1.length(), m = s2.length(), i = 0, j = 0, res = 0;

    while(i < n and j < m) {
        res ^= s1[i] ^ s2[j];
        i++; j++;
    }
    if(i < n) { res ^= s1[i]; }
    if(j < m) { res ^= s2[j]; }

    return (char)res;
}

//Pangram Checking
//Pangram is a sentence/string that has at least one occurrence of all characters form a to z
//Lower case or uppercase doesn't matter
//For example: The quick brown fox jumps over the lazy dog
bool isPangram(const string &s) {
    int n = s.length();
    if(n < 26) { return false; }
    vector<bool> visited(26, false);
    for(int i = 0; i < n; i++) {
        if(s[i] >= 'a' and s[i] <= 'z') {
            visited[s[i] - 'a'] = true;
        }
        else if(s[i] >= 'A' and s[i] <= 'Z') {
            visited[s[i] - 'A'] = true;
        }
    }
    for(int i = 0; i < 26; i++) {
        if(visited[i] == false) { return false; }
    }
    return true;
}

//__builtin_popcount() is a built-in function in GCC compiler that returns the number of set bits in an integer
