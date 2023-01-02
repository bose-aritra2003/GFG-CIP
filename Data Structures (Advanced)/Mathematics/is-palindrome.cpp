#include <iostream>
#include <cmath>

using namespace std;

bool isPalindrome(int n) {
    /**
     * Time complexity: O(n)
     */
    int temp = n;
    int rev = 0;
    while (temp > 0) {
        rev = (rev * 10) + (temp % 10);
        temp /= 10;
    }
    return rev == n;
}