// CUP PROBLEM

/* You are given n cups (user input)
 * You and your opponent get to pick one cup at a time
   alternatively from the first cup starting from left to right
 * You always pick first
 * One who picks the last cup wins
 * Then determine that for what value(s) of n you will win
 */

#include <iostream>

int main() {
    std::cout << "Enter number of cups: ";
    int n{};
    std::cin >> n;

    if(n % 2 == 0)
        std::cout << "You loose!\n";
    else
        std::cout << "You win!\n";
    return 0;
}
