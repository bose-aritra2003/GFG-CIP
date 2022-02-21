// TABLE OF A NUMBER

/* To print the integral multiples of a number upto n */

#include <iostream>

void printTable(int number, int limit) {
    for(int i = 1; i <= limit; i++)
        std::cout << number * i << '\n';
}

int main() {
    int number{}, limit{};
    std::cout << "Enter number whose table you want to generate: ";
    std::cin >> number;
    std::cout << "Upto how many multiples you want: ";
    std::cin >> limit;
    printTable(number, limit);
}