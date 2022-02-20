// Number of digits

/* Calculate the number of digits in a number */

#include <iostream>

int number_of_digits(int n) {
    int count{0};
    while (n > 0) {
        count++;
        n /= 10;
    }
    return count;
}

int main() {
    std::cout << "Enter a number to count number of digits: ";
    int number{};
    std::cin >> number;
    std::cout << number_of_digits(abs(number)) << std::endl;
    return 0;
}