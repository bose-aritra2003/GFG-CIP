// Check whether a string is a palindrome or not

#include <iostream>

bool checkPalindrome(auto &str) {
    int length = str.length();
    int mid_index = length / 2;  // For optimisation, we have done till mid-index
    for(int i = 0; i < mid_index; i++)
        if(str[i] != str[length - i - 1])
            return false;
    return true;
}

int main() {
    std::string s;
    std::getline(std::cin, s, '\n');
    std::cout << "Is it a palindrome: " << std::boolalpha << checkPalindrome(s) << '\n';
    return 0;
}