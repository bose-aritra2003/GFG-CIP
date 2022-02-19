// PRIME FACTORISATION
/* Given a number say 100
 * So its prime factorisation is 2*2*5*5
 * So the program will output 2 2 5 5
 */

// Declarations
bool isPrime(int);
void printPrimeFactorization(int);

#include <iostream>
int main() {
    int n{};
    std::cout << "Enter a positive number to check: ";
    std::cin >> n;

    std::cout << "Prime factor(s) are: ";
    printPrimeFactorization(n);
}

bool isPrime(int x) {
    // Prime number divisible only by 1 and itself
    for(int i = 2; i < x; i++) {
        if(x % i == 0)
            return false;
    }
    return true;
}

void printPrimeFactorization(int x) {
    /* We start from i = 2 since 2 is the first prime number
     * first we check whether current value i is prime or not
     * if above is true then we check divisibility of x by i
     * if divisible then we print i and change value of x to x/i
     * if above if executes we do not change value of i
     * because current i can be a prime factors multiple times in x
     * like in 100 we have 5 and 2 two times each
     * and repeat the process for x and i
     * if however x is not divisible by i or i is not prime we increase i by 1
     * and this loop continues unless i exceeds value of x
     */
    int i = 2;
    while(i <= x) {
        if(isPrime(i)) {
            if(x % i == 0) {
                std::cout << i << ' ';
                x /= i;
            }
            else
                i++;
        }
        else
            i++;
    }
}