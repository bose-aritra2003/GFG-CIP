// DIGITAL ROOT

/* To calculate the ultimate sum of digits of a number,
 * that is unless sum of digits is a single digit
 */

#include <iostream>

int number_of_digits(int n) {
    if(n == 0)
        return 1;

    int count{};
    while(n > 0) {
        count++;
        n /= 10;
    }
    return count;
}

int sum_of_digits(int n) {
    int sum{};
    short digit;
    while(n > 0) {
        digit = n % 10;
        sum += digit;
        n /= 10;
    }
    return sum;
}

int digitalRoot(int n) {
    while(true) {
        n = sum_of_digits(n);
        if(number_of_digits(n) == 1)
            return n;
    }
}

int main() {
    std::cout << "Enter a number: ";
    int n{};
    std::cin >> n;
    std::cout << digitalRoot(n) << '\n';
}

