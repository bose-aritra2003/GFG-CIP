// LARGEST OF 3 NUMBERS

#include <iostream>

int main() {
    std::cout << "Enter 3 number seperated by spaces: ";
    int a{}, b{}, c{};
    std::cin >> a >> b >> c;

    if(a >= b && a >= c)
        std::cout << a;
    else if(b >= a && b >= c)
        std::cout << b;
    else
        std::cout << c;
    return 0;
}
