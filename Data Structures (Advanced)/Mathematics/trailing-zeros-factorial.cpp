#include <iostream>

using namespace std;

int trailingZeroes(int n) {
    /**
     * Time Complexity: O(log5(n))
     * Auxiliary Space: O(1)
     */
    int count = 0;
    while (n > 0) {
        count += n / 5;
        n /= 5;
    }
    return count;
}
