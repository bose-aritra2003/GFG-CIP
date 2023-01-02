#include <iostream>
#include <cmath>

using namespace std;

unsigned long long iterativeFactorial(unsigned long long n) {
    /**
     * Time Complexity: O(n)
     * Auxiliary Space: O(1)
     */
    unsigned long long result = 1;
    for (unsigned long long i = 1; i <= n; i++) {
        result *= i;
    }
    return result;
}

unsigned long long recursiveFactorial(unsigned long long n) {
    /**
     * Time Complexity: O(n); T(n) = T(n - 1) + O(1)
     * Auxiliary Space: O(n)
     */
    if (n == 0) {
        return 1;
    }
    return n * recursiveFactorial(n - 1);
}
