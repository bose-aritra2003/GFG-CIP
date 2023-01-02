#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void addDirectedEdge(vector<vector<int>>& adj, int u, int v) {
    /**
     * Adds a directed edge from u to v
     */
    adj[u].push_back(v);
}

void addUndirectedEdge(vector<vector<int>>& adj, int u, int v) {
    /**
     * Adds a undirected edge from u to v
     */
    adj[u].push_back(v);
    adj[v].push_back(u);
}

void printGraph(vector<vector<int>>& adj) {
    /**
     * Prints the adjacency list representation of the graph
     */
    for(int i = 0; i < v; i++) {
        cout << i << ": ";
        for(auto &j: adj[i]) {
            cout << j << ' ';
        }
        cout << '\n';
    }
}

void connectedBFS(vector<vector<int>>& adj, int s, vector<bool>& visited) {
    queue<int> q;
    q.push(s);
    visited[s] = true;
    vector<int> ans;
    while(q.empty() == false) {
        int curr = q.front();
        q.pop();
        ans.push_back(curr);
        for(auto &j: adj[curr]) {
            if(visited[j] == false) {
                visited[j] = true;
                q.push(j);
            }
        }
    }
    for(auto &i: ans) {
        cout << i << ' ';
    }
}

void disconnectedBFS(vector<vector<int>>& adj) {
    /**
     * Time complexity: O(V + E)
     * Auxiliary space: Θ(V)
     */
    int v = adj.size();
    vector<bool> visited(v, false);
    for(int i = 0; i < v; i++) {
        if(visited[i] == false)
            connectedBFS(adj, i, visited);
    }
}

int main() {
    int v = 9;
    vector<vector<int>> adj(v, vector<int>());
    addUndirectedEdge(adj, 0, 1);
    addUndirectedEdge(adj, 0, 2);
    addUndirectedEdge(adj, 1, 2);
    addUndirectedEdge(adj, 3, 4);
    addUndirectedEdge(adj, 5, 6);
    addUndirectedEdge(adj, 5, 7);
    addUndirectedEdge(adj, 7, 8);
    cout << "Adjacency List:\n";
    printGraph(adj);
    cout << "BFS:\n";
    disconnectedBFS(adj);
    return 0;
}