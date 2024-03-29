# Competitive Programming Template
<br>

```
/**
 * author: bose_aritra2003
 */

#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx,avx2,fma")

#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <deque>
#include <fstream>
#include <iomanip>
#include <iterator>
#include <iostream>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>

using namespace std;

//----------------------</SHORT-HAND>------------------------
#define endl '\n'
#define int long long
#define INF LONG_LONG_MAX
#define all(x) (x).begin(),(x).end()
#define rall(x) (x).rbegin(),(x).rend()
#define fast_io ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

//----------------------</CONSTANTS>-------------------------
#define PI 3.1415926535897932384626433832795l
#define MOD 1000000007

//----------------------</FUNCTIONS>-------------------------
#define gcd(a, b) __gcd(a,b)
#define lcm(a, b) (((a)*(b))/gcd(a,b))
#define ceil(a, b) (((a)+(b)-(1))/(b))
#define search(v, x) binary_search(all(v), x)

// ----------------------</BITWISE>--------------------------
/* health_up=target variable, b=bit number to act upon 0-n */
#define BIT_SET(a, b) ((a) |= (1ULL<<(b)))
#define BIT_CLEAR(a, b) ((a) &= ~(1ULL<<(b)))
#define BIT_FLIP(a, b) ((a) ^= (1ULL<<(b)))

// '!!' to make sure this returns 0 or 1
#define BIT_CHECK(a, b) (!!((a) & (1ULL<<(b))))

#define BITMASK_SET(x, mask) ((x) |= (mask))
#define BITMASK_CLEAR(x, mask) ((x) &= (~(mask)))
#define BITMASK_FLIP(x, mask) ((x) ^= (mask))
#define BITMASK_CHECK_ALL(x, mask) (!(~(x) & (mask)))
#define BITMASK_CHECK_ANY(x, mask) ((x) & (mask))

// ----------------------</OVERLOAD>--------------------------
template <typename T, typename S>
ostream& operator<<(ostream& os, const pair<T, S>& v)
{
    os << v.first << " " << v.second;
    return os;
}
template <typename T>
ostream& operator<<(ostream& os, const vector<T>& v)
{
    for (int i = 0; i < v.size(); ++i) {
        os << v[i];
        if (i != v.size() - 1)
            os << " ";
    }
    return os;
}

//---------------------</DISJOINT SET>------------------------
class DisjointSet {
private:
    vector<int> parent;
    vector<int> set_size;
public:
    explicit DisjointSet(int capacity) {
        /**
         * @brief Construct a new Disjoint Set object
         */
        parent.resize(capacity + 1);
        set_size.resize(capacity + 1, 1);
        for(int i = 0; i < capacity + 1; i++) {
            parent[i] = i;
        }
    }
    int find(int node) {
        /**
         * @brief Find the parent of the node
         * @param node: The node to find the parent of
         * @return The parent of the node
         */
        if (parent[node] == node)
            return node;
        return parent[node] = find(parent[node]);
    }
    void unite(int x, int y) {
        /**
         * @brief Unites two sets
         * @param x: first node
         * @param y: second node
         */
        int x_root = find(x);
        int y_root = find(y);
        if(x_root == y_root)
            return;
        if (set_size[x_root] < set_size[y_root]) {
            parent[x_root] = y_root;
            set_size[y_root] += set_size[x_root];
        }
        else {
            parent[y_root] = x_root;
            set_size[x_root] += set_size[y_root];
        }
    }
    int size(int node) {
        /**
         * @brief Returns the size of the set
         * @param node: The node to find the size of
         * @return: The size of the set
         */
        return set_size[find(node)];
    }
    int count() {
        /**
         * @brief Returns the number of disjoint sets
         * @return: The number of disjoint sets
         */
        int components = 0, n = parent.size();
        for(int i = 0; i < n; i++) {
            components += (find(i) == i);
        }
        return components;
    }
};

// ----------------------</PROBLEM>---------------------------
class Problem {
private:
    int tc; //No. of testcases

    int fastPow(int base, int power) {
        /**
         * @param base: base number
         * @param power: power to raise the base to
         * @return: base^power
         */
        int res = 1;
        while (power > 0) {
            if (power & 1)
                res = res * base;
            base = base * base;
            power >>= 1;
        }
        return res;
    }

    int reverseNumber(int n) {
        /**
         * @param n: number to be reversed
         * @return: reversed number
         */
        int rev = 0;
        while (n > 0) {
            rev = rev * 10 + n % 10;
            n /= 10;
        }
        return rev;
    }

    string dec_to_bin(int n) {
        /**
         * @param n: number to convert to binary
         * @return: binary representation of n
         */
        string s = bitset<64>(n).to_string();
        const auto loc1 = s.find('1');
        if (loc1 != string::npos)
            return s.substr(loc1);
        return "0";
    }

    int bin_to_dec(string s) {
        /**
         * @param s: binary representation of n
         * @return: decimal representation of n
         */
        int n = 0;
        for (int i = 0; i < s.size(); i++)
            n += (s[i] - '0') * fastPow(2, s.size() - i - 1);
        return n;
    }

    pair<int, int> farthestCell(auto N, auto M, auto I, auto J) {
        /**
         * @param N: number of rows
         * @param M: number of columns
         * @param I: row index of starting cell
         * @param J: column index of starting cell
         * @return: pair of row and column indices of farthest cell from starting cell
         */
        pair<int, int> p{};
        // From cell(N, M)
        int d1 = N + M - I - J;
        // From Cell(1, 1)
        int d2 = I + J - 2;
        // From cell(N, 1)
        int d3 = N - I + J - 1;
        // From cell(1, M)
        int d4 = M - J + I - 1;

        // Finding out maximum
        int maxDistance = max(d1,
                              max(d2,
                                  max(d3, d4)));

        if (maxDistance == d1) {
            p.first = N;
            p.second = M;
        } else if (maxDistance == d2) {
            p.first = 1;
            p.second = 1;
        } else if (maxDistance == d3) {
            p.first = N;
            p.second = 1;
        } else if (maxDistance == d4) {
            p.first = 1;
            p.second = M;
        }
        return p;
    }

    int hardFactorial(int n) {
        /**
         * @param n: number to find hardFactorial of
         * @return: hardFactorial of n
         */
        int fact[21] = {1, 1, 2, 6, 24, 120, 720, 5040, 40320, 362880, 3628800, 39916800, 479001600, 6227020800,
                              87178291200, 1307674368000, 20922789888000, 355687428096000, 6402373705728000,
                              121645100408832000, 2432902008176640000};
        return fact[n];
    }

    int factorial(int n) {
        /**
         * @param n: number to find factorial of
         * @return: factorial of n
         */
        int res = 1;
        for (int i = 2; i <= n; i++)
            res = (res * i) % MOD;
        return res;
    }

    int nCr(int n, int r) {
        /**
         * @param n: number of elements
         * @param r: number of elements to choose from
         * @return: nCr of n and r
         */
        return hardFactorial(n) / (hardFactorial(r) * hardFactorial(n - r));
    }

    bool isPowerOfTwo(int n) {
        /**
         * @param n: number to check if it is health_up power of two
         * @return: true if n is health_up power of two, false otherwise
         */
        return n && !(n & (n - 1));
    }

    bool isPrime(int n) {
        /**
         * @param n: number to check if it is prime
         * @return: true if n is prime, false otherwise
         */
        if (n <= 1)
            return false;
        if (n == 2 or n == 3)
            return true;
        if (n % 2 == 0 or n % 3 == 0)
            return false;
        for (int i = 5; i <= sqrt(n); i = i + 6)
            if (n % i == 0 or n % (i + 2) == 0)
                return false;
        return true;
    }

    void rotateMatrix(vector<vector<char>> &matrix) {
        /**
         * @param matrix: matrix to rotate by 90 degrees
         */
        int n = matrix.size();
        for (int i = 0; i < n / 2; i++) {
            for (int j = i; j < n - i - 1; j++) {
                char temp = matrix[i][j];
                matrix[i][j] = matrix[n - j - 1][i];
                matrix[n - j - 1][i] = matrix[n - i - 1][n - j - 1];
                matrix[n - i - 1][n - j - 1] = matrix[j][n - i - 1];
                matrix[j][n - i - 1] = temp;
            }
        }
    }

    vector<string> splitString(const string& str, char delim)
    {
        string word;
        vector<string> words;
        for (auto x : str)
        {
            if (x == delim)
            {
                words.push_back(word);
                word = "";
            }
            else {
                word += x;
            }
        }
        words.push_back(word);
        return words;
    }

    //Extra functions if required

    //Main code starts here
    void execute() {
        int n;
        cin >> n;
        vector<int> arr(n);
        for(auto &i: arr)
            cin >> i;
        int digits_in_bin = (int)(log2(n)) + 1;
        int power_set = fastPow(2, digits_in_bin);
        vector<int> temp(power_set, 0);
        temp[0] = 1;
        int impossible = 0, XOR = 0;
        for(auto &i: arr){
            XOR ^= i;
           for(int j = 0; j * j < power_set; j++)
               impossible += temp[XOR ^ (j * j)];
           temp[XOR]++;
        }
        int ans = ((n * (n + 1)) / 2) - impossible;
        cout << ans << endl;
    }

public:
    explicit Problem(int t = 1) : tc(t) {
        cin >> tc;
    }

    void solve() {
        while (tc--) {
            execute();
        }
    }
};

int_fast32_t main() {
    fast_io
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    Problem().solve();
    cerr << "MyTime elapsed: " << (double) clock() / CLOCKS_PER_SEC << "s.";
    return 0;
}
```
