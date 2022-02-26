// Program to calculate product of two N x N square matrix

/* In accordance to the rules of matrix multiplication */

#include <iostream>
#include <vector>
using namespace std;

auto multiplyMatrix(const auto &matA, const auto &matB) {
    int sum = 0;
    vector<vector<int>> matC;
    vector<int> v;
    for(int r = 0; r < matA.size(); r++) {
        for(int c = 0; c < matA[r].size(); c++) {
            for(int i = 0; i < matA[c].size(); i++)
                sum += (matA[r][i] * matB[i][c]);
            v.push_back(sum);
            sum = 0;
        }
        matC.push_back(v);
        v.clear();
    }
    return matC;
}

void print(const auto &arr) {
    for(int r = 0; r < arr.size(); r++) {
        for (int c = 0; c < arr[r].size(); c++) {
            cout << arr[r][c] << '\t';
        }
        cout << '\n';
    }
}

int main() {
    vector<vector<int>> arrA = {
            {1, 2, 3},
            {4, 5, 6},
            {7, 8, 9}
    };

    vector<vector<int>> arrB = {
            {2,  4,  6},
            {8,  10, 12},
            {14, 16, 18}
    };

    auto arrC = multiplyMatrix(arrA, arrB);
    cout << "Product of:\nMATRIX A\n";
    print(arrA);
    cout << "\nand MATRIX B\n";
    print(arrB);
    cout << "\nis:\n";
    print(arrC);
    return 0;
}