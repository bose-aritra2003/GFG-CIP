//Examples of problems using hash table and hashing

#include <iostream>
#include <unordered_set>
#include <unordered_map>

using namespace std;

bool zeroSumSubArrayExists(int arr[], int n)
{
    /**
     * Given an array of integers, find if there exists a subarray with sum equal to 0.
     */

    /*
        A simple solution is to consider all subarrays one by one and
        check the sum of every subarray.
        We can run two loops: the outer loop picks a starting point i and
        the inner loop tries all subarrays starting from i .
        The time complexity of this method is O(n^2).

        We can also use hashing.
        The idea is to iterate through the array and for every element arr[i],
        calculate the sum of elements from 0 to i (this can simply be done as sum += arr[i]).
        If the current sum has been seen before, then there is a zero-sum array.
        Hashing is used to store the sum values so that we can quickly store sum and
        find out whether the current sum is seen before or not.

        Example :

        arr[] = {1, 4, -2, -2, 5, -4, 3}

        If we consider all prefix sums, we can
        notice that there is a subarray with 0
        sum when :
        1) Either a prefix sum repeats or
        2) Or prefix sum becomes 0.

        Prefix sums for above array are:
        1, 5, 3, 1, 6, 2, 5

        Since prefix sum 1 repeats, we have a subarray
        with 0 sum.

        Time Complexity of this solution can be considered as O(n)
        under the assumption that we have good hashing function that allows
        insertion and retrieval operations in O(1) time.

        Space Complexity: O(n)
        Here we required extra space for unordered_set to insert array elements.

        Auxiliary Space: O(1).
     */
    unordered_set<int> hashTable;

    // Traverse through array
    // and store prefix sums
    int prefix_sum = 0;
    for (int i = 0; i < n; i++)
    {
        prefix_sum += arr[i];

        // If prefix prefix_sum is 0, or
        // it is already present
        if (prefix_sum == 0 or hashTable.find(prefix_sum) != hashTable.end())
            return true;

        hashTable.insert(prefix_sum);
    }
    return false;
}

bool subArrayWithGivenSumExists(int arr[], int n, int sum) {
    /**
     * Given an array of integers and a number x, find if there exists a subarray with sum equal to x.
     * Example: arr[] = {3, 4, 5, 2, 1, 6} and sum = 9.
     * Output: True
     * Because subarray {4, 5} has sum 9.
     * This is a simple extension of the previous problem.
     */

    unordered_set<int> hashTable;

    // Traverse through array
    // and store prefix sums
    int prefix_sum = 0;
    for (int i = 0; i < n; i++)
    {
        prefix_sum += (arr[i]);

        // If prefix prefix_sum is sum, or
        // prefix_sum - sum is already present
        if (prefix_sum == sum or hashTable.find(prefix_sum - sum) != hashTable.end())
            return true;

        hashTable.insert(prefix_sum);
    }
    return false;
}

int longestSubArrayWithGivenSum(int arr[], int n, int sum) {
    /**
     * Given an array of integers and a number x, find the length of the longest subarray with sum equal to x.
     * Example: arr[] = {3, 4, 5, 2, 1, 6} and sum = 9.
     * Output: 2
     * The longest subarray with sum 9 is {4, 5}
     * The length of this subarray is 2.
     */

    /*
        Naive Approach:
        Consider the sum of all the sub-arrays and
        return the length of the longest sub-array having sum ‘k’.
        Time Complexity is of O(n^2).

        Efficient Approach:
        Following are the steps:
        1. Initialize sum = 0 and maxLen = 0.
        2. Create a hash table having (sum, index) tuples.
        3. For i = 0 to n-1, perform the following steps:
            3.1. Accumulate arr[i] to sum.
            3.2. If sum == k, update maxLen = i+1.
            3.3. Else check if (sum-k) is present in the hash table or not.
                 If present, then obtain index of (sum-k) from the hash table as index.
                 Now check if maxLen < (i-index), then update maxLen = (i-index).
            3.4. Check whether sum is present in the hash table or not.
                 If not present, then add it to the hash table as (sum, i) pair.
        4. Return maxLen.

        Time Complexity: O(n)
        Auxiliary Space: O(n)
     */

    unordered_map<int, int> hashTable;
    int max_len = 0;
    int prefix_sum = 0;
    for (int i = 0; i < n; i++)
    {
        prefix_sum += arr[i];
        if(prefix_sum == sum)
            max_len = i + 1;
        else if(hashTable.find(prefix_sum - sum) != hashTable.end())
            max_len = max(max_len, i - hashTable[prefix_sum - sum]);

        //Below statement ensures that only the leftmost occurrence of every prefix_sum is stored in the hash table.
        if(hashTable.find(prefix_sum) == hashTable.end())
            hashTable.insert({prefix_sum, i}); //may also use hashTable[prefix_sum] = i;
    }
    return max_len;
}

int longestSubArrayWithSameNumberOfZeroesAndOnes(int arr[], int n) {
    /**
     * Given a binary array (consisting only of 0s and 1s)
     * find the length of the longest subarray with equal number of 0s and 1s.
     * Example: arr[] = {1, 0, 1, 1, 1, 0, 0}
     * Output: 6
     * The longest subarray is {0, 1, 1, 1, 0, 0}
     */

    /*
     * This problem reduces to the longest sub array with sum 0,
     * if we just consider the 0s as -1s in the array
     */

    unordered_map<int, int> hashTable;
    int max_len = 0;
    int prefix_sum = 0;
    for (int i = 0; i < n; i++)
    {
        (arr[i] == 0) ? prefix_sum-- : prefix_sum++; //We do not modify the original array to replace 0s with -1s
        if(prefix_sum == 0)
            max_len = i + 1;
        else if(hashTable.find(prefix_sum) != hashTable.end())
            max_len = max(max_len, i - hashTable[prefix_sum]);

        //Below statement ensures that only the leftmost occurrence of every prefix_sum is stored in the hash table.
        if(hashTable.find(prefix_sum) == hashTable.end())
            hashTable.insert({prefix_sum, i}); //may also use hashTable[prefix_sum] = i;
    }
    return max_len;
}

unsigned long countDistinctElements(int arr[], int n) {
    /**
     * Given an array of integers, find the number of distinct elements.
     * Example: arr[] = {1, 2, 2, 3, 3, 3, 4, 4, 4, 4}
     * Output: 5
     * Time Complexity: Θ(n)
     * Auxiliary Space: O(n)
     */
    unordered_set<int> hashTable;
    for(int i = 0; i < n; i++)
        hashTable.insert(arr[i]);
    //Or we can skip above steps and directly write unordered_set<int> hashTable(arr, arr + n);
    return hashTable.size();
}

void printFrequencyOfElements(int arr[], int n) {
    /**
     * Given an array of integers, print the frequency of each element.
     * Example: arr[] = {10, 12, 10, 15, 10, 20, 12, 12}
     * Output:
     * 12 3
     * 20 1
     * 15 1
     * 10 3
     * Time Complexity: Θ(n)
     * Auxiliary Space: O(n)
     */
    unordered_map<int, unsigned long> hashTable;
    for(int i = 0; i < n; i++)
        hashTable[arr[i]]++;
    for(auto &pair: hashTable)
        cout << pair.first << " " << pair.second << '\n';
}

int main() {
    int arr1[] = {1, 4, 13, -3, -10, 5};
    int n1 = sizeof(arr1) / sizeof(arr1[0]);
    cout << boolalpha << zeroSumSubArrayExists(arr1, n1) << '\n';

    int arr2[] = {5, 8, 6, 13, 3, -1};
    int n2 = sizeof(arr2) / sizeof(arr2[0]);
    cout << boolalpha << subArrayWithGivenSumExists(arr2, n2, 22) << '\n';

    int arr3[] = {1, 2, -4, 5, 4, -5, 3, 0, 0};
    int n3 = sizeof(arr3) / sizeof(arr3[0]);
    cout << longestSubArrayWithGivenSum(arr3, n3, 3) << '\n';

    int arr4[] = {1, 0, 1, 1, 1, 0, 0};
    int n4 = sizeof(arr4) / sizeof(arr4[0]);
    cout << longestSubArrayWithSameNumberOfZeroesAndOnes(arr4, n4) << '\n';

    int arr5[] = {2, 2, 1, 3, 3, 4, 4, 3, 4, 4};
    int n5 = sizeof(arr5) / sizeof(arr5[0]);
    cout << countDistinctElements(arr5, n5) << '\n';

    int arr6[] = {10, 12, 10, 15, 10, 20, 12, 12};
    int n6 = sizeof(arr6) / sizeof(arr6[0]);
    printFrequencyOfElements(arr6, n6);

    return 0;
}