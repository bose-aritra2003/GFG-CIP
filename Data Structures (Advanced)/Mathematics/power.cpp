#include <iostream>
#include <vector>

using namespace std;

//TASK: Calculate x^n

unsigned long long naivePow(int x, int n) {
    /**
     * Time complexity: O(n)
     * Auxiliary space: O(1)
     */
    unsigned long long result = 1;
    for (int i = 0; i < n; i++) {
        result *= x;
    }
    return result;
}

unsigned long long recursivePow(int x, int n) {
    /**
     * Time complexity: O(n)
     * Auxiliary space: O(n)
     */
    if (n == 0) {
        return 1;
    }
    return x * recursivePow(x, n - 1);
}

unsigned long long optimisedRecursivePow(int x, int n) {
    /**
     * Time complexity: O(log n)
     * Auxiliary space: O(log n)
     */
    if (n == 0) {
        return 1;
    }
    if (n % 2 == 1) {
        return x * optimisedRecursivePow(x, n - 1);
    }
    else {
        unsigned long long b = optimisedRecursivePow(x, n / 2);
        return b * b;
    }
}

unsigned long long binaryExponentiation(int x, int n) {
    /**
     * Time complexity: O(log n)
     * Auxiliary space: O(1)
     */
    unsigned long long result = 1;
    while (n > 0) {
        if (n & 1) { //or n % 2 == 1
            result *= x;
        }
        x *= x;
        n >>= 1; //or n /= 2
    }
    return result;
}


int main() {
    int x, n;
    cin >> x >> n;
    cout << naivePow(x, n);
    return 0;
}