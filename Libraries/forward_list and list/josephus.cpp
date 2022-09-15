# include <iostream>
# include <list>

using namespace std;

int getJosephusSurvivor(int n, int k) {
    /**
     * Time complexity: O(n * k)
     * Auxiliary space: O(n)
     */
    list<int> people;
    for (int i = 1; i <= n; i++) {
        people.push_back(i);
    }
    auto it = people.begin();
    while (people.size() > 1) {
        for (int i = 1; i < k; i++) {
            it++;
            if (it == people.end()) {
                it = people.begin();
            }
        }
        it = people.erase(it);
        if (it == people.end()) {
            it = people.begin();
        }
    }
    return people.front();
}


int main() {
    int n = 7, k = 3;
    cout << getJosephusSurvivor(n, k) << endl;
}
