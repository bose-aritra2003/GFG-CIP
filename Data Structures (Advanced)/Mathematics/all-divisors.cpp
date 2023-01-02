#include <iostream>

using namespace std;

//TASK: Print all the divisors of n in sorted order

void allDivisorsNaiveSorted(int n) {
    /**
     * Time Complexity: O(n)
     */
    for (int i = 1; i <= n; i++) {
        if (n % i == 0) {
            cout << i << " ";
        }
    }
}

//Below implementation would print the divisors in arbitrary order
void optimizedAllDivisors(int n) {
    /**
     * Time Complexity: O(sqrt(n))
     */
    for (int i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            cout << i << " ";
            if (i != n / i) {
                cout << n / i << " ";
            }
        }
    }
}

//But how to use the above approach to print in sorted order without effecting TC
void allDivisorsSorted(int n) {
    /**
     * Time Complexity: O(sqrt(n))
     */
    int i = 1;
    while(i * i <= n) {
        if (n % i == 0) {
            cout << i << " ";
        }
        i++;
    }
    while(i >= 1) {
        if (n % i == 0 && i != n / i) {
            cout << n / i << " ";
        }
        i--;
    }
}

int main() {
    int n;
    cin >> n;
    allDivisorsSorted(n);
    return 0;
}