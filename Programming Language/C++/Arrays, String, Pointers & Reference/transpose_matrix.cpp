// Program to do transpose of a matrix

/* Diagonal elements do not change.
 * Only elements at r != c and r <= c
 * are swapped like r, c = c, r
 */

#include <iostream>
#include <vector>
using namespace std;

void transposeOf(auto &arr) {
    for(int r = 0; r < arr.size(); r++)
        for(int c = 0; c < arr[r].size(); c++) {
            if(r != c and r <= c)
                swap(arr[r][c], arr[c][r]);
        }
}

void print(const auto &arr) {
    for(int r = 0; r < arr.size(); r++) {
        for (int c = 0; c < arr[r].size(); c++) {
            cout << arr[r][c] << ' ';
        }
        cout << '\n';
    }
}

int main() {
    vector<vector<int>> arr = {
            {1, 2, 3},
            {4, 5, 6},
            {7, 8, 9}
    };
    print(arr);
    cout << '\n';
    transposeOf(arr);
    cout << '\n';
    print(arr);
}
