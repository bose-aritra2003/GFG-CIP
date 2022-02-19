// FIRST DIGIT
/* A program to output the first digit of a given number
 * say we have 9657 then first digit is 9
 */

#include <iostream>

int firstDigit(int x) {
    /* We repeatedly divide a number by 10 unless it becomes a single digit number
     * and that single digit is the first digit of that number
     */
    if(x < 0)
        x = -x;
    while(x >= 10)
        x /= 10;
    return x;
}

int main() {
    int n{};
    std::cout <<  "Enter a number to get its first digit: ";
    std::cin >> n;

    std::cout << firstDigit(n) << std::endl;
    return 0;
}