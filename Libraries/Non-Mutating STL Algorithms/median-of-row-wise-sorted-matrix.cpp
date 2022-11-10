#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*
 * Let's say given matrix is:
 * mat[][] = {
 *              {1, 10, 20},
 *              {15, 25, 35},
 *              {5, 30, 40}
 *           }
 * So we have all elements in sorted fashion as: 1, 5, 10, 15, 20, 25, 30, 35, 40
 * Thus the median is: 20
 */

int medianOfRowWiseSortedMatrix(vector<vector<int>>& matrix) {
    /**
     * Time complexity: O(r * log(max - min) * log(c))
     *                  where r and c are the number of rows and columns respectively
     * Space complexity: O(1)
     */
    int n = matrix.size(), m = matrix[0].size();
    int sz = n * m;
    int med_pos = (sz + 1)/2;
    int min_ele = matrix[0][0], max_ele = matrix[0][m - 1];
    for(int r = 1; r < n; r++) {
        if(matrix[r][0] < min_ele) {
            min_ele = matrix[r][0];
        }
        if(matrix[r][m - 1] > max_ele) {
            max_ele = matrix[r][m - 1];
        }
    }
    int low = min_ele, high = max_ele;
    while(low < high) {
        int mid = low + (high - low)/2;
        int count_smaller = 0;
        for(int r = 0; r < n; r++) {
            count_smaller += (upper_bound(matrix[r].begin(), matrix[r].end(), mid) - matrix[r].begin());
        }
        if(count_smaller < med_pos) {
            low = mid + 1;
        }
        else {
            high = mid;
        }
    }
    return low;
}

int main() {
    vector<vector<int>> arr = {
            {1, 10, 20},
            {15, 25, 35},
            {5, 30, 41}
    };
    int ans = medianOfRowWiseSortedMatrix(arr);
    cout << ans << endl;
}