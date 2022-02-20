// Factorial of a number

/* Factorial of 5 = 1 * 2 * 3 * 4 * 5 */

#include <iostream>

int factorial(int n) {
    int f = 1;
    for(int i = 1; i <= n; i++) {
        f *= i;
    }
    return f;
}

int main() {
    std::cout << "Enter an integer to find out its factorial: ";
    int number{};
    std::cin >> number;
    std::cout << factorial(number) << '\n';
}
