#include <iostream>
#include <vector>

using namespace std;

//TASK: Calculate the Modular Multiplicative Inverse of 'a' under modulo 'm'


//METHOD 1
int naiveModInverse(int A, int M) {
    /**
     * Time Complexity: O(M)
     * Auxiliary Space: O(1)
     */
    for (int X = 1; X < M; X++)
        if (((A % M) * (X % M)) % M == 1)
            return X;
}


//METHOD 2
// Function for extended Euclidean Algorithm
int gcdExtended(int a, int b, int* x, int* y) {

    // Base Case
    if (a == 0) {
        *x = 0, *y = 1;
        return b;
    }

    // To store results of recursive call
    int x1, y1;
    int gcd = gcdExtended(b % a, a, &x1, &y1);

    // Update x and y using results of recursive
    // call
    *x = y1 - (b / a) * x1;
    *y = x1;

    return gcd;
}
// Function to find modulo inverse of a
void optimisedModInverse(int A, int M) {
    /**
     * Time Complexity: O(log M)
     * Auxiliary Space: O(log M)
     */
    int x, y;
    int g = gcdExtended(A, M, &x, &y);
    if (g != 1)
        cout << "Inverse doesn't exist";
    else {

        // m is added to handle negative x
        int res = (x % M + M) % M;
        cout << "Modular multiplicative inverse is " << res;
    }
}


//METHOD 3
int bestModInverse(int A, int M) {
    /**
     * Time Complexity: O(log M)
     * Auxiliary Space: O(1)
     */
    int m0 = M;
    int y = 0, x = 1;

    if (M == 1)
        return 0;

    while (A > 1) {
        // q is quotient
        int q = A / M;
        int t = M;

        // m is remainder now, process same as
        // Euclid's algo
        M = A % M, A = t;
        t = y;

        // Update y and x
        y = x - q * y;
        x = t;
    }

    // Make x positive
    if (x < 0)
        x += m0;

    return x;
}
