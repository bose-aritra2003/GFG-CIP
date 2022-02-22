// Program to check whether array is sorted or not

/* Take every element as max from beginning and traverse from the next
 * array elements to check if any element is smaller or not.
 * If in any such traversal smaller element is found in the elements
 * after the element being worked upon then the array is unsorted
 */

#include <iostream>
#include <vector>
bool isSorted(std::vector<int> arr) {
    for(int i = 1; i < arr.size(); i++) {
        if(arr[i] < arr[i-1])
            return false;
    }
    return true;

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

    if(isSorted(arr))
        std::cout << "Yes\n";
    else
        std::cout << "No\n";
}