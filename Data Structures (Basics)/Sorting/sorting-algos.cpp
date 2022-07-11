//Sorting algorithms

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void bubbleSort(int arr[], int n) {
    /**
     * Bubble sort is a simple sorting algorithm that works by repeatedly swapping adjacent elements if they are in wrong order.
     * Time complexity: Θ(n^2)
     * Auxiliary space: O(1)
     */
    int i, j;
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

void optimisedBubbleSort(int arr[], int n) {
    /**
     * If in any pass array is sorted we skip the further passes
     * and declare the whole array as sorted
     * Time complexity: O(n^2)
     * Auxiliary space: O(1)
     */
    int i, j;
    for (i = 0; i < n - 1; i++) {
        bool swapped = false;
        for (j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }
        if (!swapped)
            break;
    }
}

void selectionSort(int arr[], int n) {
    /**
     * Selection sort is a simple sorting algorithm that works
     * by selecting the smallest element from the array and swapping it with the first element.
     * Then the second smallest element is selected and swapped with the second element and so on.
     * Time complexity: Θ(n^2)
     * Auxiliary space: O(1)
     */
    int i, j, min_idx;
    for (i = 0; i < n - 1; i++) {
        min_idx = i;
        for (j = i + 1; j < n; j++) {
            if (arr[j] < arr[min_idx]) {
                min_idx = j;
            }
        }
        swap(arr[min_idx], arr[i]);
    }
}

void insertionSort(int arr[], int n) {
    /**
     * Insertion sort is a simple sorting algorithm that works by maintaining a sorted sublist
     * in the right hand side of the array and then arranging the remaining elements in order.
     * Time complexity: O(n^2)
     * Auxiliary space: O(1)
     */
    int i, key, j;
    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;
        while (j >= 0 and arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

//Merge sort algorithm & its dependency functions
void mergeTwoSortedArrays(const int A[], int n, const int B[], int m, int arr[], int low = 0) {
    /**
     * Merge two sorted arrays into one sorted array
     * Time complexity: O(n+m)
     * Auxiliary space: O(n+m)
     */
    int i = 0, j = 0, k = low;
    while(i < n and j < m) {
        if(A[i] <= B[j]) {
            arr[k] = A[i];
            i++;
        }
        else {
            arr[k] = B[j];
            j++;
        }
        k++;
    }
    //Pushing the remaining elements of the larger array to the new array
    while(i < n) {
        arr[k] = A[i];
        i++;
        k++;
    }
    while(j < m) {
        arr[k] = B[j];
        j++;
        k++;
    }
}

void mergeTwoSortedSubarraysOfAGivenArray(int arr[], const int low, const int mid, const int high) {
    /**
     * Merge two sorted subarrays of a given array into one sorted array.
     * The subarrays are one from low to mid and another from mid+1 to high.
     * Time complexity: O(high - low)
     * Auxiliary space: O(high - low)
     */
    int left_size = mid - low + 1;
    int *left = new int[left_size];
    for(int i = 0; i < left_size; i++)
        left[i] = arr[low + i];

    int right_size = high - mid;
    int *right = new int[right_size];
    for(int i = 0; i < right_size; i++) {
        right[i] = arr[mid + i + 1];
    }
    mergeTwoSortedArrays(left, left_size, right, right_size, arr, low);
}

void mergeSort(int arr[], int low, int high) {
    /**
     * Merge sort is a divide and conquer algorithm.
     * It works by breaking the array into two halves and then merging the two sorted halves.
     * Time complexity: O(n log n)
     * Auxiliary space: O(n)
     */
    if(low >= high) //Base case
        return;
    int mid = low + (high - low) / 2; //To avoid overflow when low + high is large
    mergeSort(arr, low, mid);
    mergeSort(arr, mid + 1, high);
    mergeTwoSortedSubarraysOfAGivenArray(arr, low, mid, high);
}

//Understanding quick sort
int naivePartition(int arr[], int low, int high, int pivot) {
    /**
     * Partition the array around the pivot element using naive approach
     * Time complexity: Θ(n)
     * Auxiliary space: Θ(n)
     */
    int temp[high - low + 1], idx = 0;
    for(int i = low; i <= high; i++) {
        if(arr[i] < arr[pivot]) {
            temp[idx] = arr[i];
            idx++;
        }
    }
    for(int i = low; i <= high; i++) {
        if(arr[i] == arr[pivot]) {
            temp[idx] = arr[i];
            idx++;
        }
    }

    int last_pivot_idx = low + idx - 1;
    for(int i = low; i <= high; i++) {
        if(arr[i] > arr[pivot]) {
            temp[idx] = arr[i];
            idx++;
        }
    }
    for(int i = low; i <= high; i++) {
        arr[i] = temp[i - low];
    }
    return last_pivot_idx;
}

int lomutoPartition(int arr[], int low, int high) {
    /**
     * Partition the array around the pivot element using Lomuto's partition scheme
     * Time complexity: Θ(n)
     * Auxiliary space: Θ(1)
     */
    int pivot = arr[high]; // If pivot is given, then just swap it with the last element and then continue
    int i = low - 1;
    for(int j = low; j < high; j++) {
        if(arr[j] <= pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return i + 1;
}

int hoarePartition(int arr[], int low, int high) {
    /**
     * Partition the array around the pivot element using Hoare's partition scheme
     * Time complexity: Θ(n)
     * Auxiliary space: Θ(1)
     */
    int pivot = arr[low]; // If pivot is given, then just swap it with the first element and then continue
    int i = low - 1, j = high + 1;
    while(true) {
        do {
            i++;
        } while(arr[i] < pivot);
        do {
            j--;
        } while(arr[j] > pivot);
        if(i >= j)
            return j;
        swap(arr[i], arr[j]);
    }
}

void quickSortLomuto(int arr[], int low, int high) {
    /**
     * Quick sort is a divide and conquer algorithm.
     * It works by breaking the array into two halves and then recursively sorting the two halves.
     * Time complexity: Θ(n log n)
     * Auxiliary space: Θ(log n)
     */
    if(low >= high)
        return;
    int pivot = lomutoPartition(arr, low, high);
    quickSortLomuto(arr, low, pivot - 1);
    quickSortLomuto(arr, pivot + 1, high);
}

void quickSortHoare(int arr[], int low, int high) {
    /**
     * Quick sort is a divide and conquer algorithm.
     * It works by breaking the array into two halves and then recursively sorting the two halves.
     * Time complexity: Θ(n log n)
     * Auxiliary space: Θ(log n)
     */
    if(low >= high)
        return;
    int pivot = hoarePartition(arr, low, high);
    quickSortHoare(arr, low, pivot);
    quickSortHoare(arr, pivot + 1, high);
}

void cycleSort(int arr[], int n) {
    /**
     * Cycle sort work only for a range of consecutive elements like 1 to N or 1 + k to N + k.
     * Time complexity: O(n-1) + O(n) = O(2n-1) = O(n)
     * Auxiliary space: Θ(1)
     */
    //Find minimum element in array
    int min = arr[0];
    for(int i = 1; i < n; i++) {
        if(arr[i] < min)
            min = arr[i];
    }
    //Cycle sort
    int i = 0, correct_idx;
    while(i < n) {
        if(arr[i] - min == i)
            i++;
        else {
            correct_idx = arr[i] - min;
            swap(arr[i], arr[correct_idx]);
        }
    }
}

void countingSort(int arr[], int n, int k) {
    /**
     * Counting sort works for a small range of non negative integer elements
     * Time complexity: Θ(n+k)
     * Auxiliary space: Θ(n+k)
     */
    int count[k];
    for(int i = 0; i <= k; i++)
        count[i] = 0;
    for(int i = 0; i < n; i++)
        count[arr[i]]++;
    for(int i = 1; i <= k; i++)
        count[i] += count[i - 1];
    int output[n];
    for(int i = n - 1; i >= 0; i--) {
        //We traverse from back to front to maintain stability of the algorithm
        output[count[arr[i]] - 1] = arr[i];
        count[arr[i]]--;
    }
    for(int i = 0; i < n; i++)
        arr[i] = output[i];
}

void radixSort(int arr[], int n) {
    /**
     * Radix sort works for a range of non negative integer elements
     * Time complexity: Θ(d*(n+b))
     * Auxiliary space: Θ(n+b)
     */
    int max = arr[0];
    for(int i = 1; i < n; i++) {
        if(arr[i] > max)
            max = arr[i];
    }
    for(int exp = 1; max / exp > 0; exp *= 10) {
        //Similar to counter sort
        int count[10] = {0};
        for(int i = 0; i < n; i++)
            count[(arr[i] / exp) % 10]++;
        for(int i = 1; i < 10; i++)
            count[i] += count[i - 1];
        int output[n];
        for(int i = n - 1; i >= 0; i--) {
            output[count[(arr[i] / exp) % 10] - 1] = arr[i];
            count[(arr[i] / exp) % 10]--;
        }
        for(int i = 0; i < n; i++)
            arr[i] = output[i];
    }
}

void bucketSort(int arr[], int n, int k) {
    /**
     * Bucket sort works for a range of non negative integer elements
     * Time complexity: Θ(n+k)
     * Auxiliary space: Θ(n+k)
     */
    //Find max value
    int max_val = arr[0];
    for(int i = 1; i < n; i++) {
        if(arr[i] > max_val)
            max_val = arr[i];
    }
    max_val++;
    vector<int> bkt[k]; //Array of vectors
    //Fill the buckets
    for(int i = 0; i < n; i++) {
        int bi = (k * arr[i]) / max_val;
        bkt[bi].push_back(arr[i]);
    }
    //Sort individual buckets
    for(int i = 0; i < k; i++) {
        sort(bkt[i].begin(), bkt[i].end());
    }
    int idx = 0;
    //Join the buckets
    for(int i = 0; i < k; i++) {
        for(int j : bkt[i]) {
            arr[idx++] = j;
        }
    }
}

int main() {
    int arr[] = {5, 6, 5, 2};
    countingSort(arr, 4, 7);
    for(int i : arr)
        cout << i << " ";
    return 0;
}