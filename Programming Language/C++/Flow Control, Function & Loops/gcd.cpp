// Greatest Common Divisor

/* The highest common factor common to both numbers
 * that completely divides both numbers.
 * Logic is first we get the minimum of two numbers
 * then iterate from 1 to min(a, b) and then
 * if an iterable divides both a and b we store it as gcd.
 */

#include <iostream>

int gcd(int a, int b) {
    int gcd{};
    for(int i = 1; i <= std::min(a, b); i++) {
        if (a % i == 0 and b % i == 0)
            gcd = i;
    }
    return gcd;
}

int main() {
    std::cout << "Enter two numbers: ";
    int a{}, b{};
    std::cin >> a >> b;
    std::cout << gcd(a, b) << '\n';
}