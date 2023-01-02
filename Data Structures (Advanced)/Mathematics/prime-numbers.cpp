#include <iostream>

using namespace std;

bool isPrimeNaive(int n) {
    /**
     * Time complexity: O(n)
     */
    if (n < 2) {
        return false;
    }
    for (int i = 2; i < n; i++) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}

bool isPrimeOptimised(int n) {
    /**
     * Time complexity: O(sqrt(n))
     */
    if (n < 2) {
        return false;
    }
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}


bool isPrimeBest(int n) {
    /**
     * Time complexity: O(sqrt(n)); 3 times faster than above
     */
    if (n < 2) {
        return false;
    }
    if (n == 2 || n == 3) {
        return true;
    }
    if (n % 2 == 0 || n % 3 == 0) {
        return false;
    }
    for (int i = 5; i * i <= n; i += 6) {
        if (n % i == 0 || n % (i + 2) == 0) {
            return false;
        }
    }
    return true;
}

//Prime Factorisation
void naivePrimeFactors(int n) {
    /**
     * Time complexity: O(sqrt(n))
     */
    if(n < 2) {
        cout << "No prime factors" << endl;
        return;
    }
    for(int i = 2; i * i <= n; i++) {
        while(n % i == 0) {
            cout << i << " ";
            n /= i;
        }
    }

    //When largest prime factor of n has only 1 power
    if(n > 1) {
        cout << n << " ";
    }
}

void optimisedPrimeFactors(int n) {
    /**
     * Time complexity: O(sqrt(n))
     */
    if(n < 2) {
        cout << "No prime factors" << endl;
        return;
    }
    while(n % 2 == 0) {
        cout << 2 << " ";
        n /= 2;
    }
    while(n % 3 == 0) {
        cout << 3 << " ";
        n /= 3;
    }
    for(int i = 5; i * i <= n; i += 6) {
        while(n % i == 0) {
            cout << i << " ";
            n /= i;
        }
        while(n % (i + 2) == 0) {
            cout << (i + 2) << " ";
            n /= (i + 2);
        }
    }
    //2 and 3 are already handled
    if(n > 3) {
        cout << n << " ";
    }
}

int main() {
    int n;
    cin >> n;
    optimisedPrimeFactors(n);
    return 0;
}