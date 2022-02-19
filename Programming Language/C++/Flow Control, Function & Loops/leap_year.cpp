// LEAP YEAR
/* Conditions are:
 * 1) Divisible by 4
 * 2) But not divisible by 100
 * 3) Unless divisible by 400
 */

#include <iostream>
int main() {
    int n{};
    std::cin >> n;

    if(n % 400 == 0)
        std::cout << "Leap year";
    else if(n % 100 == 0)
        std::cout << "Not a leap year";
    else if(n % 4 == 0)
        std::cout << "Leap year";
    else:
        std::cout << "Not a leap year"
    return 0;
}
