// BINARY TO DECIMAL

/* Convert a binary number to its decimal form.
 * eg: 101 = 1*(2^2) + 0*(2^1) + 1*(2^0) = 5
 */

#include <iostream>
#include <cmath>

long binary_to_decimal(long binary) {
    long decimal{};
    int i{0};
    while(binary > 0) {
        decimal += (binary % 10) * pow(2, i);
        i++;
        binary /= 10;
    }
    return decimal;
}

int main() {
    std::cout << "Enter a binary number without leading zeroes: ";
    long binary{};
    std::cin >> binary;
    std::cout << binary_to_decimal(binary) << '\n';
}