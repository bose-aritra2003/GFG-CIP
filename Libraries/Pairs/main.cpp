# include <iostream>
# include <vector>

using namespace std;

void sortArrayAccordingToOther(int a[], char b[], int n) {
    /**
     * Time Complexity: O(n log n)
     * Auxiliary Space: O(n)
     */
    pair<int, char> c[n];
    for(int i = 0; i < n; i++) {
        c[i] = {a[i], b[i]};
    }
    sort(c, c+n);
    for(int i = 0; i < n; i++) {
        cout << c[i].second << ' ';
    }
}

int main() {
    int a[] = {3, 1, 2};
    char b[] = {'a', 'b', 'c'};
    sortArrayAccordingToOther(a, b, 3);
    return 0;
}