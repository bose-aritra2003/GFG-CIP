// SIMPLE CALCULATOR
/* There will be 3 integer inputs
 * First input will be for which type of operation
 * 1 -> Addition, 2 -> Subtraction, 3 -> Multiplication
 * Next 2 inputs will be the operands
 * If for the first input user enters anything other than 1/2/3 the program will show invalid input
 */

#include <iostream>
int main() {
    int n, x, y;
    std::cin >> n >> x >> y;
    switch(n) {
        case 1: std::cout << (x + y);
                break;
        case 2: std::cout << (x - y);
                break;
        case 3: std::cout << (x * y);
                break;
        default:
                std::cout << "Invalid Input!\n";
    }
    return 0;
}
