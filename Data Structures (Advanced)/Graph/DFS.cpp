#include <iostream>
#include <vector>

using namespace std;

void addDirectedEdge(vector<vector<int>>& adj, int u, int v) {
    /**
     * Adds a directed edge from u to v
     */
    adj[u].push_back(v);
}
void addUndirectedEdge(vector<vector<int>>& adj, int u, int v) {
    /**
     * Adds an undirected edge between u and v
     */
    adj[u].push_back(v);
    adj[v].push_back(u);
}

void printGraph(vector<vector<int>>& adj) {
    /**
     * Prints the adjacency list representation of the graph
     */
    for(int i = 0; i < adj.size(); i++) {
        cout << i << ": ";
        for(auto &j: adj[i]) {
            cout << j << ' ';
        }
        cout << '\n';
    }
}

void connectedDFS(vector<vector<int>>& adj, int s, vector<bool>& visited) {
    visited[s] = true;
    cout << s << ' ';
    for(auto &i: adj[s]) {
        if(visited[i] == false) {
            connectedDFS(adj, i, visited);
        }
    }
}

void disconnectedDFS(vector<vector<int>>& adj) {
    /**
     * Time complexity: O(V + E)
     */
    int v = adj.size();
    vector<bool> visited(v, false);
    for(int i = 0; i < v; i++) {
        if(visited[i] == false) {
            connectedDFS(adj, i, visited);
        }
    }
}


int main() {
    int v = 5;
    vector<vector<int>> adj(v, vector<int>());
    addUndirectedEdge(adj, 0, 1);
    addUndirectedEdge(adj, 0, 2);
    addUndirectedEdge(adj, 1, 3);
    addUndirectedEdge(adj, 1, 4);
    addUndirectedEdge(adj, 2, 3);
    addUndirectedEdge(adj, 3, 4);
    cout << "Adjacency List:\n";
    printGraph(adj);
    cout << "DFS:\n";
    disconnectedDFS(adj);
    return 0;
}