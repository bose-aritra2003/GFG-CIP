//Examples of problems using Recursion

#include <iostream>

using namespace std;

int floorLogBaseXvalueN(int base, int n)
{
    /**
     * Returns the floor of log base x value of n
     */
    if(n < base)
        return 0;
    else
        return 1 + floorLogBaseXvalueN(base, n/base);
}

int decimalToBinary(int n)
{
    /**
     * Returns the binary representation of a decimal n
     */
    if(n == 0)
        return 0;
    else
        return (n % 2) + 10 * decimalToBinary(n/2);
}

void printIntegers_N_to_1(int n)
{
    /**
     * Prints all the integers from n to 1
     * Recurrence relation: T(n) = T(n-1) + Θ(1)
     * Time Complexity: Θ(n)
     * Auxiliary Space: O(1)
     */
    if(n <= 0)
        return;
    cout << n << '\n';
    printIntegers_N_to_1(n - 1);
}

void printIntegers_1_to_N(int n)
{
    /**
     * Prints all the integers from 1 to n
     * Recurrence relation: T(n) = T(n-1) + Θ(1)
     * Time Complexity: Θ(n)
     * Auxiliary Space: O(n)
     */
    if(n <= 0)
        return;
    printIntegers_1_to_N(n - 1);
    cout << n << '\n';
    //If we convert this into equivalent tail recursive code then the
    //auxiliary space will turn to Θ(1)
}

int tailRecursiveFactorial(int n, int k = 1)
{
    /**
     * Returns the factorial of n using tail recursion
     */
    if(n <= 1)
        return k;
    return tailRecursiveFactorial(n - 1, k * n);
}

int nthFibonacciNumber(int n)
{
    /**
     * Returns the nth fibonacci number
     */
    if(n <= 1)
        return n;
    return nthFibonacciNumber(n - 1) + nthFibonacciNumber(n - 2);
}

int tailRecursiveConsecutiveSum(int n, int k = 0)
{
    /**
     * Returns the sum of first n natural numbers using tail recursion
     * Recurrence relation: T(n) = T(n-1) + Θ(1)
     * Time Complexity: Θ(n)
     * Auxiliary Space: O(1)
     */
    if(n <= 0)
        return k;
    return tailRecursiveConsecutiveSum(n - 1, k + n);
}

bool stringIsPalindrome(string s, int start = 0, int end = 1)
{
    /**
     * Returns true if the string is a palindrome
     * Recurrence relation: T(n) = T(n-2) + Θ(1)
     * Time Complexity: O(n)
     * Auxiliary Space: O(n/2) = O(n)
     */
    if(start >= end)
        return true;
    return (s[start] == s[end]) and stringIsPalindrome(s, start + 1, end - 1);
}

int sumOfDigits(int n, int k = 0) {
    /**
     * Returns the sum of digits of a non negative integer
     * Time complexity: Θ(number of digits in n)
     * Auxiliary space: Θ(1)
     */
    if(n <= 0)
        return k;
    return sumOfDigits(n / 10, k + (n % 10));
}

int cutRopeIntoMaxPartsFromGivenPieces(int n, int a, int b, int c) {
    /**
     * Returns the maximum number of pieces that can be cut from a rope of length n,
     * using the given lengths of the pieces a, b and c
     * Time complexity: O(3^n)
     */
    if(n == 0)
        return 0;
    if(n < 0)
        return -1;
    int res = max(cutRopeIntoMaxPartsFromGivenPieces(n - a, a, b, c),
                  max(cutRopeIntoMaxPartsFromGivenPieces(n - b, a, b, c),
                      cutRopeIntoMaxPartsFromGivenPieces(n - c, a, b, c)));
    //Corner case: n=9, a=2, b=2, c=2
    if(res == -1)
        return -1;
    return res + 1;
    //This problem has a better solution using dynamic programming
}

void allSubsequencesOfString(const string &s, const string& curr = "", int i = 0) {
    /**
     * Prints all the subsequences of a string
     */
    if(i == s.length()) {
        cout << curr << '\n';
        return;
    }
    allSubsequencesOfString(s, curr + s[i], i + 1);
    allSubsequencesOfString(s, curr, i + 1);
}

void towerOfHanoi(int n, char source = 'A', char destination = 'C', char aux = 'B') {
    /**
     * Prints all the moves required to move n disks from
     * source to destination using aux as the auxiliary tower
     * Recurrence relation: T(n) = 2T(n-1) + Θ(1)
     * Time complexity: O(2^n)
     */
    if(n == 1) {
        cout << "Move disk 1 from " << source << " to " << destination << '\n';
        return;
    }
    //First move n-1 discs from A to B using C as the auxiliary tower
    towerOfHanoi(n - 1, source, aux, destination);
    //Move the nth disk from A to C
    cout << "Move disk " << n << " from " << source << " to " << destination << '\n';
    //Move n-1 discs from B to C using A as the auxiliary tower
    towerOfHanoi(n - 1, aux, destination, source);
}

int main() {
    printIntegers_N_to_1(5);
    printIntegers_1_to_N(5);
    cout << tailRecursiveFactorial(5) << '\n';
    cout << nthFibonacciNumber(5) << '\n';
    cout << tailRecursiveConsecutiveSum(5) << '\n';
    cout << stringIsPalindrome("madam") << '\n';
    cout << sumOfDigits(123) << '\n';
    cout << cutRopeIntoMaxPartsFromGivenPieces(9, 2, 2, 2) << '\n';
    allSubsequencesOfString("abc");
    towerOfHanoi(3);
    return 0;
}