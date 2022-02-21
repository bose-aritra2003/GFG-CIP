// FIBONACCI SEQUENCE

/* If f(n) is a number in the fibonacci series then f(n) = f(n-1) + f(n-2) */

#include <iostream>

void fibonacci(int n) {
    int a{0}, b{1};
    std::cout << a << ' ' << b << ' ';
    for(int i = 2; i < n; i++) {
        int c = a + b;
        std::cout << c << ' ';
        a = b;
        b = c;
    }
}

int main() {
    std::cout << "Enter number of elements: ";
    int a{};
    std::cin >> a;
    fibonacci(a);
}