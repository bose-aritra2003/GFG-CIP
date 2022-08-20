//Sorting examples

#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

int minimumDifferenceInAnArray(int arr[], int n) {
    /**
     * Given an array of n integers, find the minimum difference between any two elements in the array.
     * Example:
     * Input: arr[] = {1, 8, 12, 5, 18}
     * Output: 3
     * The minimum difference is between 8 and 5.
     * Overall time complexity O(nlogn)
     */
    int min_diff = INT_MAX;
    sort(arr, arr + n); //O(nlogn)
    for(int i = 1; i < n; i++) {
        //O(n)
        min_diff = min(min_diff, abs(arr[i] - arr[i - 1]));
    }
    return min_diff;
}

void intersectionOfTwoSortedArrays(const int arr1[], int n1, const int arr2[], int n2) {
    /**
     * Given two sorted arrays, find the intersection of the two arrays.
     * Example:
     * Input: arr1[] = {3, 5, 10, 10, 10, 15, 15, 20}
     *        arr2[] = {5, 10, 10, 15, 30}
     * Output: Intersection of the two arrays is {5, 10, 15}
     * Overall time complexity O(n1 + n2)
     */
    int i = 0, j = 0;
    while(i < n1 and j < n2) {
        if(i > 0 and (arr1[i] == arr1[i - 1])) {
            //skip duplicates
            i++;
        }
        if(j > 0 and (arr2[j] == arr2[j - 1])) {
            //skip duplicates
            j++;
        }
        //Similar to merge function of merge sort
        else if(arr1[i] < arr2[j]) {
            i++;
        }
        else if(arr1[i] > arr2[j]) {
            j++;
        }
        else if(arr1[i] == arr2[j]){
            cout << arr1[i] << " "; //or arr2[j]
            i++;
            j++;
        }
    }
}

void unionOfTwoSortedArrays(int arr1[], int n1, int arr2[], int n2) {
    /**
     * Given two sorted arrays, find the union of the two arrays.
     * Example:
     * Input: arr1[] = {3, 5, 10, 10, 10, 15, 15, 20}
     *        arr2[] = {5, 10, 10, 15, 30}
     * Output: Union of the two arrays is {3, 5, 10, 15, 20}
     * Overall time complexity O(n1 + n2)
     */
    int i = 0, j = 0;
    //Similar to merge function of merge sort
    while(i < n1 and j < n2) {
        if(i > 0 and (arr1[i] == arr1[i - 1])) {
            //skip duplicates in arr1
            i++;
        }
        if(j > 0 and (arr2[j] == arr2[j - 1])) {
            //skip duplicates in arr2
            j++;
        }
        //Similar to merge function of merge sort
        else if (arr1[i] < arr2[j]) {
            cout << arr1[i] << " ";
            i++;
        }
        else if (arr1[i] > arr2[j]) {
            cout << arr2[j] << " ";
            j++;
        }
        else if(arr1[i] == arr2[j]){
            cout << arr1[i] << " "; //or arr2[j]
            i++;
            j++;
        }
    }
    //Remaining elements in the larger array
    while(i < n1) {
        if(i > 0 and (arr1[i] == arr1[i - 1])) {
            //print remaining elements of arr1
            cout << arr1[i] << " ";
        }
        i++;
    }
    while(j < n2) {
        if(j > 0 and (arr2[j] == arr2[j - 1])) {
            //print remaining elements of arr2
            cout << arr2[j] << " ";
        }
        j++;
    }
}

//Count inversions in an array
//Time complexity: O(nlogn)
//Auxiliary spacxe: O(n)
int countAndMerge(int arr[], int l, int m, int r) {
    int n1 = m - l + 1;
    int n2 = r - m;
    int left[n1], right[n2];
    //Split the array and store them in left and right
    for(int i = 0; i < n1; i++) {
        left[i] = arr[l + i];
    }
    for(int i = 0; i < n2; i++) {
        right[i] = arr[m + 1 + i];
    }
    int count = 0, i = 0, j = 0, k = l;
    while(i < n1 and j < n2) {
        if(left[i] < right[j]) {
            arr[k] = left[i];
            i++;
        }
        else {
            arr[k] = right[j];
            j++;
            count += (n1 - i);
        }
        k++;
    }
    while(i < n1) {
        arr[k] = left[i];
        i++;
        k++;
    }
    while(j < n2) {
        arr[k] = right[j];
        j++;
        k++;
    }
    return count;
}
int countInversions(int arr[], int low, int high) {
    int res = 0;
    if(low < high) {
        int mid = low + (high-low) / 2;
        res += countInversions(arr, low, mid);
        res += countInversions(arr, mid + 1, high);
        res += countAndMerge(arr, low, mid, high);
    }
    return res;
}

//Find the kth smallest element in an array
//Also known as QuickSelect algorithm
int lomutoPartition(int arr[], int low, int high) {
    int pivot = arr[high];
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
int kthSmallestElement(int arr[], int n, int k) {
    /**
     * Find the kth smallest element in an array
     * Time complexity: O(n) average
     * Auxiliary space: Θ(1)
     */
     int low = 0, high = n-1;
    while(low < high) {
        int pi = lomutoPartition(arr, low, high);
        if(pi == k-1)
            return arr[pi];
        else if(pi > k-1)
            high = pi - 1;
        else
            low = pi + 1;
    }
    return INT_MIN;
}

void putNegativesFirstLomuto(int arr[], int n) {
    int i = -1;
    for(int j = 0; j < n; j++) {
        if(arr[j] < 0) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
}

void putNegativesFirstHoare(int arr[], int n) {
    int i = -1, j = n;
    while(true) {
        do {
            i++;
        } while(arr[i] < 0);
        do {
            j--;
        } while(arr[j] >= 0);
        if(i >= j)
            break;
        swap(arr[i], arr[j]);
    }
}

void dnfSort(int arr[], int n) {
    /**
     * Dutch National Flag Algorithm.
     * Here you are given an array containing only 0s, 1s and 2s.
     * You have to sort the array such that 0s comes first, 1s comes next and 2s comes last.
     * Time complexity: Θ(n)
     * Auxiliary space: Θ(1)
     */
    int low = 0, mid = 0, high = n - 1;
    while(mid <= high) {
        if(arr[mid] == 0) {
            swap(arr[low], arr[mid]);
            low++;
            mid++;
        }
        else if(arr[mid] == 1) {
            mid++;
        }
        else {
            swap(arr[mid], arr[high]);
            high--;
        }
    }
}

void mergeOverlappingIntervals(vector<pair<int, int>> &intervals) {
    /**
     * Merge overlapping intervals
     * Time complexity: O(nlogn)
     * Auxiliary space: O(1)
     */
    sort(intervals.begin(), intervals.end(),
         [](const pair<int, int> &a, const pair<int, int> &b) {
        return a.first < b.first;
    });
    int res = 0;
    for(int i = 1; i < intervals.size(); i++) {
        if(intervals[res].second >= intervals[i].first) {
            intervals[res].second = max(intervals[res].second, intervals[i].second);
            intervals[i].first = min(intervals[res].first, intervals[i].first);
        }
        else {
            res++;
            intervals[res] = intervals[i];
        }
    }
}

int meetMaxGuests(int arr[], int dep[], int n)
{
    /**
     * Meeting maximum number of guests
     * Time complexity: O(nlogn)
     * Auxiliary space: O(1)
     */
    sort(arr, arr + n);
    sort(dep, dep + n);
    int i = 0, j = 0, max_guests = 0, curr_guests = 0;
    while(i < n and j < n) {
        if(arr[i] <= dep[j]) {
            curr_guests++;
            i++;
        }
        else {
            curr_guests--;
            j++;
        }
        max_guests = max(max_guests, curr_guests);
    }
    return max_guests;
}

int main() {
    int arr[] = {900, 600, 700};
    int dep[] = {1000, 800, 730};
    cout << meetMaxGuests(arr, dep, 3) << endl;
}
