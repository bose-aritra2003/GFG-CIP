#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> floydWarshall(vector<vector<int>>& adj) {
    /**
     * Time complexity: O(V^3)
     * Auxiliary space: O(V^2)
     */
    int n = adj.size();
    for(int via = 0; via < n; via++) {
        for(int from = 0; from < n; from++) {
            for(int to = 0; to < n; to++) {
                if(adj[from][via] != -1 && adj[via][to] != -1) {
                    if(adj[from][to] == -1) {
                        adj[from][to] = adj[from][via] + adj[via][to];
                    }
                    else {
                        adj[from][to] = min(adj[from][to], adj[from][via] + adj[via][to]);
                    }
                }
            }
        }
    }
    return adj;
}