// Sum of elements in an array

/* Program will traverse through each element of the array
 * and a variable sum will cumulatively add up each element in the array.
 */

#include <iostream>
#include <vector>

int sumArray(auto vector) {
    int sum{0};
    for(int x: vector) {
        sum += x;
    }
    return sum;
}

int main() {
    std::vector<int> arr;
    std::cout << "Type an integer and press enter to push, type 0 when you wanna end.\n";
    int element{1};
    while(element) {
        std::cin >> element;
        if (element != 0)
            arr.push_back(element);
    }
    std::cout << sumArray(arr) << std::endl;
}