// PRIME CHECK

/* A prime number is a number divisible by 1 and itself only */

#include <iostream>

bool checkPrime(int n) {
    if (n == 1 or n == 0)
        return false;
    for(int i = 2; i < n; i++) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}

int main() {
    std::cout << "Enter a number to check: ";
    int number{};
    std::cin >> number;
    std::cout << std::boolalpha << checkPrime(number) << '\n';
}