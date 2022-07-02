//Searching algorithms

#include <iostream>
using namespace std;

int iterativeBinarySearch(const int arr[], int n, int x) {
    /**
     * Given a sorted array and an integer.
     * The function returns -1 if it finds the integer in the array.
     * And if it finds the integer in the array then it return the index of that element.
     * Time Complexity: O(log n)
     * Auxiliary Space: O(1)
     */

    int low{0}, high{n - 1}, mid{0};
    while(low <= high) {
        mid = (low + high) / 2;
        if(arr[mid] == x)
            return mid;
        else if(arr[mid] < x)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return -1;
}

int recursiveBinarySearch(const int arr[], int n, int x) {
    /**
     * Same as above but this time using recursion
     * Time complexity: O(log n)
     * Auxiliary Space: O(log n)
     */

    int low{0}, high{n - 1}, mid{0};
    mid = (low + high) / 2;
    if(arr[mid] == x)
        return mid;
    else if(arr[mid] < x)
        recursiveBinarySearch(arr+mid+1, high - mid, x);
    else
        recursiveBinarySearch(arr, mid, x);
}

int main() {
    int arr[] = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100};
    cout << iterativeBinarySearch(arr, 10, 70) << '\n';
    cout << iterativeBinarySearch(arr, 10, 110) << '\n';
    cout << iterativeBinarySearch(arr, 10, 50) << '\n';
    cout << iterativeBinarySearch(arr, 10, 25) << '\n';
    cout << iterativeBinarySearch(arr, 10, 40) << '\n';
    cout << iterativeBinarySearch(arr, 10, 80) << '\n';
    cout << iterativeBinarySearch(arr, 10, 20) << '\n';
    return 0;
}