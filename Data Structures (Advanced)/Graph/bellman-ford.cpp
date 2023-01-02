#include <iostream>
#include <vector>

using namespace std;

vector<int> bellmanFord(vector<vector<int>>& edges, int source) {
    /**
     * Time Complexity: O(V * E)
     * Auxiliary Space: O(V)
     */
    int n = edges.size();
    vector<int> dist(n, INT_MAX);
    dist[source] = 0;
    for(int i = 0; i < n - 1; i++) {
        for(auto &edge : edges) {
            int u = edge[0], v = edge[1], w = edge[2];
            if(dist[u] != INT_MAX && dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
            }
        }
    }
    //nth relaxation to check for negative cycles
    for(auto &edge : edges) {
        int u = edge[0], v = edge[1], w = edge[2];
        if(dist[u] != INT_MAX && dist[u] + w < dist[v]) {
            cout << "Negative cycle detected" << endl;
            return {-1};
        }
    }
    return dist;
}