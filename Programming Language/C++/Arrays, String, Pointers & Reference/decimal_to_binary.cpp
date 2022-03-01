// Decimal to Binary

#include <iostream>

std::string decimalToBinary(int dec) {
    std::string binary;
    while(dec > 0) {
        binary += std::to_string(dec % 2) + '0';  // Because ASCII of '0' is 48 and '1' is 49
        dec /= 2;
    }
    std::reverse(binary.begin(), binary.end());
    return binary;
}

int main() {
    int dec;
    std::cin >> dec;
    std::cout << "Binary equivalent is: " << decimalToBinary(dec) << '\n';
    return 0;
}