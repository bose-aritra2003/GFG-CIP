// Count the number of distinct elements in an array

/* We will have two loops
 * Outer loop will consider value from leftmost side of the loop
 * Then considering that value we will se using the inner loop
 * whether there is any element on the left side of current element
 * that is equal to that element. If not then we increase counter by 1
 * other counter remains as it is.
 */

#include <iostream>
#include <vector>

int countDistinct(auto vector) {
    int count{1};
    for(int i = 1; i < vector.size(); i++) {
        bool isDistinct = true;
        for(int j = 0; j < i; j++) {
            if(vector[i] == vector[j]) {
                isDistinct = false;
                break;
            }
        }
        if(isDistinct)
            count++;
    }
    return count;
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
    std::cout << countDistinct(arr) << std::endl;
}