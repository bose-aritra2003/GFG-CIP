// Divisors of a number

/* Positive integers that can divide a number fully are its divisors */

#include <iostream>

void print_divisors(int n) {
    for(int i = 1; i <= n; i++) {
        if (n % i == 0) {
            if (i != n)
                std::cout << i << ", ";
            else
                std::cout << i << '\n';
        }
    }
}

int main() {
    std::cout << "Enter an integer to find out its divisors: ";
    int number{};
    std::cin >> number;
    print_divisors(number);
}