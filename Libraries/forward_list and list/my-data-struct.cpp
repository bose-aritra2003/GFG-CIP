# include <iostream>
# include <vector>
# include <list>

using namespace std;

class MyDataStruct {
private:
    list<int> l;

public:
    void insert(int x) {
        l.push_back(x);
    }
    void replace(int x, vector<int>& seq) {
        auto it = find(l.begin(), l.end(), x);
        if(it == l.end())
            return;
        it = l.erase(it);
        l.insert(it, seq.begin(), seq.end());
    }
    void print() {
        for(auto &i: l) {
            cout << i << " ";
        }
    }
};


int main() {
    MyDataStruct mds;
    mds.insert(1);
    mds.insert(2);
    mds.insert(3);
    mds.insert(4);
    mds.insert(5);
    mds.insert(6);
    mds.insert(7);
    mds.insert(8);
    mds.insert(9);
    mds.insert(10);
    mds.print();
    cout << endl;
    vector<int> v = {11, 12, 13};
    mds.replace(5, v);
    mds.print();
    cout << endl;
    return 0;
}
