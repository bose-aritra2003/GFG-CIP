/*
 * Bridges in a Graph
 * Leetcode question link: https://leetcode.com/problems/critical-connections-in-a-network/
 *
 * Time Complexity: O(V + 2E)
 * Auxiliary Space Complexity: O(V + 2E) + O(3N)
 */


class Solution {
private:
    int timer = 1;
    void dfs(int node, int parent, vector<bool>& vis, vector<vector<int>>& adj, vector<int>& time, vector<int>& low, vector<vector<int>>& bridges) {
        vis[node] = true;
        time[node] = low[node] = timer;
        timer++;for(auto &it: adj[node]) {
            if(it == parent) {
                continue;
            }
            if(vis[it] == false) {
                dfs(it, node, vis, adj, time, low, bridges);
                low[node] = min(low[node], low[it]);
                if(low[it] > time[node]) {
                    bridges.push_back({it, node});
                }
            }
            else {
                low[node] = min(low[node], low[it]);
            }
        }
    }
public:
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<vector<int>> adj(n);
        for(auto &it: connections) {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        vector<bool> vis(n, false);
        vector<int> time(n);
        vector<int> low(n);
        vector<vector<int>> bridges;
        dfs(0, -1, vis, adj, time, low, bridges);
        return bridges;
    }
};