#include <iostream>
#include <vector>

using namespace std;


//Check whether kth bit is set or not
bool isKthBitSet_LeftShift(int n, int k) {
    //Left shift 1 to the kth position and take & with original number
    return n & (1 << (k - 1));
}
bool isKthBitSet_RightShift(int n, int k) {
    //Right shift kth bit of original number to position 1 and then take & with 1
    return (n >> (k - 1)) & 1;
}



//Count set bits in a number
int naiveCountSetBits(int n) {
    /**
     * Time complexity: O(32)
     */
    int count = 0;
    for(int i = 0; i < 32; i++) {
        count += ((n & (1 << i)) > 0);
    }
    return count;
}
int brianKernighanAlgorithm(int n) {
    /**
     * Time complexity: O(no. of set bits)
     */
    int count = 0;
    while (n) {
        n = n & (n - 1);
        count++;
    }
    return count;
}
//Best method: LookUp Table
class CountSetBits {
private:
    int table[256];
    void preCompute() {
        table[0] = 0;
        for(int i = 1; i < 256; i++) {
            table[i] = (i & 1) + table[i / 2];
        }
    }
public:
    int lookupTable(int n) {
        /**
         * Time complexity: O(1)
         */
        int count = table[n & 0xff];
        n = n >> 8;
        count += table[n & 0xff];
        n = n >> 8;
        count += table[n & 0xff];
        n = n >> 8;
        count += table[n & 0xff];
        return count;
        /* If you want to extend this solution for 64 bits
         * then you need to add 4 more lines of code
         * count += table[n & 0xff];
         * n = n >> 8;
         * count += table[n & 0xff];
         * n = n >> 8;
         * count += table[n & 0xff];
         * n = n >> 8;
         * count += table[n & 0xff];
         */
    }
};

//Check whether number is a power of 2
bool naiveIsPowerOf2(int n) {
    if(n == 0) {
        return false;
    }
    while(n != 1) {
        if(n & 1) {
            return false;
        }
        n = n >> 1;
    }
    return true;
}
bool optimisedIsPowerOf2(int n) {
    int count = brianKernighanAlgorithm(n);
    return count == 1;
}
bool bestIsPowerOf2(int n) {
    return n && !(n & (n - 1));
}


//Find the only odd occurring number in an array / Find missing number
int naiveFindOddOccurringNumber(int arr[], int n) {
    /**
     * Time complexity: O(n^2)
     */
    int count = 0;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(arr[i] == arr[j]) {
                count++;
            }
        }
        if(count & 1) {
            return arr[i];
        }
    }
    return -1;
}
int optimisedFindOddOccurringNumber(int arr[], int n) {
    /**
     * Time complexity: O(n)
     */
    int res = 0;
    for(int i = 0; i < n; i++) {
        res = res ^ arr[i];
    }
    return res;
}
int missingNumber(vector<int> v) {
    /**
     * Time complexity: O(n)
     */
    int res = 0;
    for(int i : v) {
        res = res ^ i;
    }
    for(int i = 1; i <= v.size() + 1; i++) {
        res = res ^ i;
    }
    return res;
}


//Find the two odd occurring numbers in an array
vector<int> naiveFindTwoOddOccurringNumbers(int arr[], int n) {
    /**
     * Time complexity: O(n^2)
     */
    int count = 0;
    vector<int> ans;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(arr[i] == arr[j]) {
                count++;
            }
        }
        if(count & 1) {
            ans.push_back(arr[i]);
        }
    }
    return ans;
}
vector<int> optimisedFindTwoOddOccurringNumbers(vector<int> arr) {
    /**
     * Time complexity: O(n)
     */
    int XOR = 0, n = arr.size(), x = 0, y = 0;
    for(int i = 0; i < n; i++) {
        XOR = XOR ^ arr[i];
    }
    int mask = XOR & ~(XOR - 1);
    for(int i = 0; i < n; i++) {
        if(arr[i] & mask) {
            x = x ^ arr[i];
        }
        else {
            y = y ^ arr[i];
        }
    }
    vector<int> ans;
    ans.push_back(x);
    ans.push_back(y);
    return ans;
}


//Power Set of a given set
void powerSet(string s) {
    /**
     * Time complexity: O(n * 2^n)
     */
    int n = s.size();
    for(int i = 0; i < (1 << n); i++) {
        for(int j = 0; j < n; j++) {
            if(i & (1 << j)) {
                cout << s[j];
            }
        }
        cout << endl;
    }
}


int main() {
    powerSet("abcd");
    return 0;
}