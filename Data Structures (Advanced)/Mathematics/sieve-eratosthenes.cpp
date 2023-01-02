#include <iostream>
#include <vector>

using namespace std;

//TASK: Print all prime numbers smaller than or equal to n

void sieveOfEratosthenes(int n) {
    /**
     * Time complexity: O(n log(log(n)))
     */
    vector<bool> prime(n + 1, true);

    for (int p = 2; p * p <= n; p++)
    {
        // If prime[p] is not changed, then it is a prime
        if (prime[p])
        {
            // Update all multiples of p
            for (int i = p * 2; i <= n; i += p) {
                prime[i] = false;
            }
        }
    }

    // Print all prime numbers
    for (int p=2; p<=n; p++) {
        if (prime[p])
            cout << p << " ";
    }
}

void optimisedSieve(int n) {
    /**
     * Time Complexity: O(n log(log n))
     */
    vector<bool> prime(n + 1, true);

    for (int p = 2; p * p <= n; p++)
    {
        // If prime[p] is not changed, then it is a prime
        if (prime[p])
        {
            // Update all multiples of p
            for (int i = p * p; i <= n; i += p) {
                prime[i] = false;
            }
        }
    }

    // Print all prime numbers
    for (int p=2; p<=n; p++) {
        if (prime[p]) {
            cout << p << " ";
        }
    }
}


int main() {
    int n;
    cin >> n;
    optimisedSieve(n);
    return 0;
}