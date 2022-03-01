// Search index of occurrence of a word in a string

#include <iostream>

void printIndex(auto &s, auto &p) {
    int found = s.find(p);
    while(found != std::string::npos) {
        std::cout << "Text found at index: " << found << '\n';
        found = s.find(p, found + 1);
    }
}

int main() {
    std::string str, word;
    getline(std::cin, str);
    getline(std::cin, word);
    printIndex(str, word);
    return 0;
}