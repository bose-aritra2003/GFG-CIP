// Binary to Decimal

#include <iostream>
#include <cmath>

int binaryToDecimal(auto &bin) {
    int decimal{0};
    int len = bin.length();
    for(int i = len - 1; i >= 0; i--)
        decimal += static_cast<int>(bin[i] - '0') * pow(2, len - i - 1);
        // 0 has ascii value 48. So 48 - 48 = 0, the 1 has ASCII value 49 so 49 - 48 = 1
        // Because static_cast from char type to int returns its ASCII value.
    return decimal;
}

int main() {
    std::string s;
    std::getline(std::cin, s, '\n');
    std::cout << "Decimal equivalent is: " << binaryToDecimal(s) << '\n';
    return 0;
}