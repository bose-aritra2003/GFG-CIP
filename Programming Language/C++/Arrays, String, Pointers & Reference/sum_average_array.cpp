// Sum and average of elements in an array

/* Program will traverse through each element of the array
 * and a variable sum will cumulatively add up each element in the array.
 * And then in another function average, the sum will be divided by the
 * number of elements in the array and return the value which is average.
 */

#include <iostream>
#include <vector>
#include <iomanip>

int sumArray(auto vector) {
    int sum{0};
    for(int x: vector) {
        sum += x;
    }
    return sum;
}

double averageArray(auto vector) {
    double length{static_cast<double>(vector.size())};
    double avg{sumArray(vector) / length};
    return avg;
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
    std::cout << std::setprecision(4) << averageArray(arr) << std::endl;
}
