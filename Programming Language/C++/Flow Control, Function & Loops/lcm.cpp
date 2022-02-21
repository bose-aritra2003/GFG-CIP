// Least Common Multiple

/* LCM of 6 and 9 is 18, LCM of 8 and 9 is 72, etc */

#include <iostream>

int lcm(int a, int b) {
    int lcm{};
    for(int i = a*b; i >= std::max(a, b); i--) {
        if (i % a == 0 and i % b == 0)
            lcm = i;
    }
    return lcm;
}

int main() {
    std::cout << "Enter two numbers: ";
    int a{}, b{};
    std::cin >> a >> b;
    std::cout << lcm(a, b) << '\n';
}