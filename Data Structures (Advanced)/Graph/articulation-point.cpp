/*
 * Articulation points in a graph
 * GfG problem link: https://practice.geeksforgeeks.org/problems/articulation-point-1/1
 *
 * Time complexity: O(V + 2E) + O(N)
 * Auxiliary Space: O(3N)
 */



class Solution {
private:
    int timer = 1;
    void dfs(int node, int parent, vector<bool>& vis, vector<int> adj[], vector<int>& time, vector<int>& low, vector<bool>& mark) {
        vis[node] = true;
        time[node] = low[node] = timer;
        timer++;
        int child = 0;
        for(auto &it: adj[node]) {
            if(it == parent) {
                continue;
            }
            if(!vis[it]) {
                dfs(it, node, vis, adj, time, low, mark);
                low[node] = min(low[node], low[it]);
                if(low[it] >= time[node] && parent != -1) {
                    mark[node] = true;
                }
                child++;
            }
            else {
                low[node] = min(low[node], time[it]);
            }
        }
        if(child > 1 && parent == -1) {
            mark[node] = true;
        }
    }
public:
    vector<int> articulationPoints(int V, vector<int>adj[]) {
        vector<bool> vis(V, false);
        vector<int> time(V);
        vector<int> low(V);
        vector<bool> mark(V, false);
        for(int i = 0; i < V; i++) {
            if(!vis[i]) {
                dfs(i, -1, vis, adj, time, low, mark);
            }
        }
        vector<int> ans;
        for(int i = 0; i < V; i++) {
            if(mark[i]) {
                ans.push_back(i);
            }
        }
        if(ans.empty()) {
            return -1;
        }
        return ans;
    }
};