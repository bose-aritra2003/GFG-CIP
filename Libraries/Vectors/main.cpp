# include <iostream>
# include <vector>

using namespace std;

vector<int> smallerElements(int arr[], int n, int k) {
    vector<int> v;
    for(int i = 0; i < n; i++) {
        if(arr[i] < k) {
            v.push_back(arr[i]);
        }
    }
    return v;
}

void printRollAndMarksWithMarksInSorted(int marks[], int roll[], int n) {
    vector<pair<int, int>> v(n); //Since we will have n elements as pair only
    for(int i = 0; i < n; i++) {
        v[i] = {marks[i], roll[i]};
    }
    sort(v.begin(), v.end(), greater<pair<int, int>>());
    for(auto &x: v) {
        cout << x.second << ' ' << x.first << '\n';
    }
}

int main() {
    int roll[] = {101, 103, 105};
    int marks[] = {80, 70, 90};
    int n = sizeof(roll) / sizeof(roll[0]);
    printRollAndMarksWithMarksInSorted(marks, roll, n);
}