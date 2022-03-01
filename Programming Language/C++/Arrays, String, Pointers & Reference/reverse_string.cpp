// Reverse a string

#include <iostream>

std::string reverseString(auto &str) {
    int l = str.length();
    std::string new_str;
    for(int i = l - 1; i >= 0; i--)
        new_str += str[i];
    return new_str;
}

int main() {
    std::string s;
    std::getline(std::cin, s, '\n');
    std::cout << "Reverse of the string is: " << reverseString(s) << '\n';
    return 0;
}