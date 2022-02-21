// NEXT PRIME NUMBER

/* We will be given a number n,
 * and we need to output the immediate next prime to n
 */

#include <iostream>

bool checkPrime(int n) {
    if (n == 1 or n == 0)
        return false;
    for(int i = 2; i < n; i++) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}

int nextPrime(int number) {
    int i = number + 1;
    while(true) {
        if(checkPrime(i))
            return i;
        i++;
    }
}

int main() {
    std::cout << "Enter a number: ";
    int n{};
    std::cin >> n;
    std::cout << nextPrime(n) << '\n';
}

