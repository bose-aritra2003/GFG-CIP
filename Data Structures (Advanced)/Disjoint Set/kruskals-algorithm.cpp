#include <iostream>
#include <vector>

using namespace std;

class DisjointSet {
private:
    vector<int> parent;
    vector<int> rank;
public:
    explicit DisjointSet(int x) {
        parent.resize(x + 1);
        rank.resize(x + 1, 0);
        for(int i = 0; i < x; i++) {
            parent[i] = i;
        }
    }
    int find(int x) {
        if (parent[x] == x)
            return x;
        return parent[x] = find(parent[x]);
    }
    void unite(int x, int y) {
        int x_root = find(x);
        int y_root = find(y);
        if(x_root == y_root)
            return;
        if(rank[x_root] < rank[y_root]) {
            parent[x_root] = y_root;
        }
        else if(rank[x_root] > rank[y_root]) {
            parent[y_root] = x_root;
        }
        else {
            parent[y_root] = x_root;
            rank[x_root]++;
        }
    }
};

bool myCmp(vector<int>& a, vector<int>& b) {
    return a[0] < b[0];
}

//Kruskal's algorithm
//Graph is given as {wt, u, v}
int mstSum(vector<vector<int>>& graph, int V) {
    /**
     * Time complexity: O(E log E) or O(E log V)
     * Auxiliary space: O(V) used by the dsu
     */
    //O(E log E)
    sort(graph.begin(), graph.end(), myCmp);
    DisjointSet ds(V);
    int sum = 0;
    //O(E)
    for(auto& edge : graph) {
        int wt = edge[0];
        int u = edge[1];
        int v = edge[2];
        if(ds.find(u) != ds.find(v)) {
            ds.unite(u, v);
            sum += wt;
        }
    }
    return sum;
}
