# include <iostream>
# include <vector>

using namespace std;

// Recursion
int fib_Rec(int n) {
    /**
     * Time complexity: O(2^n)
     * Auxiliary Space: O(n)
     */
    if(n == 0 || n == 1) {
        return n;
    }
    return fib_Rec(n - 1) + fib_Rec(n - 2);
}

// Memoization
int fib_Memo(int n) {
    /**
     * Time complexity: O(n)
     * Auxiliary Space: O(n)
     */
    static vector<int> memo(n + 1, -1);
    if(memo[n] == -1) {
        if(n == 0 || n == 1) {
            memo[n] = n;
        }
        else {
            memo[n] = fib_Rec(n - 1) + fib_Rec(n - 2);
        }
    }
    return memo[n];
}

// Tabulation
int fib_Tab(int n) {
    /**
     * Time complexity: O(n)
     * Auxiliary Space: O(n)
     */
    vector<int> table(n + 1);
    table[0] = 0; table[1] = 1;
    for(int i = 2; i <= n; i++) {
        table[i] = table[i - 1] + table[i - 2];
    }
    return table[n];
}

// Space Optimisation
int fib_Space(int n) {
    /**
     * Time complexity: O(n)
     * Auxiliary Space: O(1)
     */
    if(n <= 1) {
        return n;
    }
    int prev_2 = 0, prev_1 = 1;
    for(int i = 2; i <= n; i++) {
        int curr_i = prev_1 + prev_2;
        prev_2 = prev_1;
        prev_1 = curr_i;
    }
    return prev_1;
}

int main() {
    cout << fib_Rec(20)  << endl
         << fib_Memo(20) << endl
         << fib_Tab(20)  << endl
         << fib_Space(20)<< endl;
    return 0;
}