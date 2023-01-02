#include <iostream>
#include <cmath>

using namespace std;

int countDigitsIterative(int n) {
    int count = 0;
    while (n != 0) {
        n /= 10;
        count++;
    }
    return count;
}

int countDigitsRecursive(int n) {
    if (n == 0) {
        return 0;
    }
    return 1 + countDigitsRecursive(n / 10);
}

int countDigitsLogarithmic(int n) {
    return floor(log10(n) + 1);
}