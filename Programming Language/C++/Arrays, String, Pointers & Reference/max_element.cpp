// Largest element in an array

/* First the maximum will be the first element of the array.
 * Then we will traverse through the array to look for any other
 * element that is more than this element (current maximum), if yes
 * then we store that element as the maximum and continue traversal.
 * At the end we have the maximum.
 */

#include <iostream>
#include <vector>

int maxArrayElement(auto vector) {
    int max = vector[0];
    for(int x: vector) {
        if(x > max)
            max = x;
    }
    return max;
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
    std::cout << maxArrayElement(arr) << std::endl;
}