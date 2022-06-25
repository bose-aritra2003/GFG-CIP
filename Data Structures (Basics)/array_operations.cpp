//Array operations

#include <iostream>
using namespace std;

int linearSearchArrayElement(const int arr[], int n, int x)
{
    /**
     * Time complexity: O(n)
     * Auxiliary space: O(1)
     */
    for(int i = 0; i < n; i++)
        if (arr[i] == x)
            return i;
    return -1;
}

int insertArrayElement(int arr[], int n, int cap, int x, int pos) {
    /**
     * Time complexity: O(n)
     * Auxiliary space: O(1)
     */
    if (n == cap)
        return n;
    for (int i = n; i > pos; i--)
        arr[i] = arr[i - 1];
    arr[pos] = x;
    return n+1;
}

int deleteArrayElement(int arr[], int n, int x) {
    /**
     * Time complexity: O(n)
     * Auxiliary space: O(1)
     */
    int idx = linearSearchArrayElement(arr, n, x);
    if(idx == -1)
        return n;
    for(int i = idx; i < n-1; i++)
        arr[i] = arr[i+1];
    arr[n-1] = 0;
    return n-1;
}

int largestElementInArray(const int arr[], int n) {
    /**
     * Time complexity: Θ(n)
     * Auxiliary space: O(1)
     */
    int i, max_element_index = 0;
    for (i = 1; i < n; i++)
        if (arr[i] > arr[max_element_index])
            max_element_index = i;
    return max_element_index;
}

bool isArraySorted(const int arr[], int n) {
    /**
     * Time complexity: O(n)
     * Auxiliary space: O(1)
     */
    for(int i = 0; i < n-1; i++)
        if(arr[i] > arr[i+1])
            return false;
    return true;
}

int secondLargestArrayElement(const int arr[], int n) {
    /**
     * Time complexity: Θ(n)
     * Auxiliary space: O(1)
     */
    int max_element_idx = 0, second_max_element_idx = -1;
    for(int i = 1; i < n; i++) {
        if(arr[i] > arr[max_element_idx]) {
            second_max_element_idx = max_element_idx;
            max_element_idx = i;
        }
        else if(arr[i] != arr[max_element_idx])
            if(second_max_element_idx == -1 or arr[i] > arr[second_max_element_idx])
                second_max_element_idx = i;
    }
    return second_max_element_idx;
}

int reverseArraySection(int arr[], int start, int end) {
    /**
     * Time complexity: Θ(end)
     * Auxiliary space: O(1)
     */
    for (int i = start, j = end - 1; i < j; i++, j--) {
        //swap arr[i] and arr[j] without using a temporary variable
        //may also use swap(arr[i], arr[j])
        arr[i] = arr[i] + arr[j];
        arr[j] = arr[i] - arr[j];
        arr[i] = arr[i] - arr[j];
    }
    return end;
}

int removeArrayDuplicates(int arr[], int n) {
    /**
     * Time complexity: Θ(n)
     * Auxiliary space: O(1)
     */
    int i = 0;
    for (int j = 1; j < n; j++)
        if (arr[i] != arr[j]) {
            arr[++i] = arr[j];
        }
    return i+1;
}

int leftRotateArrayByOne(int arr[], int n) {
    /**
     * Time complexity: Θ(n)
     * Auxiliary space: O(1)
     */
    int temp = arr[0];
    for (int i = 0; i < n-1; i++)
        arr[i] = arr[i+1];
    arr[n-1] = temp;
    return n;
}

int leftRotateArrayByD(int arr[], int n, int d) {
    /**
     * Time complexity: Θ(n)
     * Auxiliary space: O(1)
     */
    reverseArraySection(arr, 0, d);
    reverseArraySection(arr, d, n);
    reverseArraySection(arr, 0, n);
    return n;
}

int moveArrayZeroesToEnd(int arr[], int n) {
    /**
     * Time complexity: Θ(n)
     * Auxiliary space: O(1)
     */
    int count_non_zeroes = 0;
    for(int i = 0; i < n; i++)
        if(arr[i] != 0) {
            swap(arr[i], arr[count_non_zeroes]);
            count_non_zeroes++;
        }
    return n;
}

int main() {
    int arr[] = {10, 0, 3, 0, 0, 8, 6, 1, 9, 3};
    int n = sizeof(arr)/sizeof(arr[0]);
}
