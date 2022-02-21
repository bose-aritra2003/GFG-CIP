// DECIMAL TO BINARY

/* Convert a decimal value to binary value */

#include <iostream>

long decimal_to_binary(int decimal) {
    std::string binary_str{};
    while(decimal >= 1){
        binary_str += std::to_string(decimal % 2);
        decimal /= 2;
    }
    std::reverse(binary_str.begin(), binary_str.end());
    long binary{std::stoi(binary_str)};
    return binary;
}

int main() {
    std::cout << "Enter a decimal number to get its binary: ";
    int decimal{};
    std::cin >> decimal;
    std::cout << decimal_to_binary(decimal) << '\n';
}

