#include <bits/stdc++.h>
using namespace std;


//How to print the shortest path that Dijkstra's Algorihtm tells
class Solution {
  public:
    vector<int> shortestPath(int n, int m, vector<vector<int>>& edges) {
        vector<vector<pair<int, int>>> adj(n + 1);
        for(auto &i: edges) {
            adj[i[0]].push_back({i[1], i[2]});
            adj[i[1]].push_back({i[0], i[2]});
        }
        vector<int> parent;
        for(int i = 0; i <= n; i++) {
            parent.push_back(i);
        }
        vector<int> dis(n + 1, 1e9);
        dis[1] = 0;
        set<pair<int, int>> s;
        s.insert({0, 1});
        while(!s.empty()) {
            pair<int, int> f = *s.begin();
            s.erase(f);
            int node = f.second, d = f.first;
            for(auto &i: adj[node]) {
                int nb = i.first, weight = i.second;
                if(dis[nb] > d + weight) {
                    dis[nb] = d + weight;
                    s.insert({dis[nb], nb});
                    parent[nb] = node;
                }
            }
        }
        if(dis[n] == 1e9) {
            return {-1};
        }
        vector<int> ans;
        int node = n;
        while(parent[node] != node) {
            ans.push_back(node);
            node = parent[node];
        }
        ans.push_back(1);
        reverse(ans.begin(), ans.end());
        return ans;
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> edges;
        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }

        Solution obj;
        vector<int> res = obj.shortestPath(n, m, edges);
        for (auto x : res) {
            cout << x << " ";
        }
        cout << "\n";
    }
}