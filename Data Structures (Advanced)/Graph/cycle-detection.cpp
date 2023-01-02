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

bool helperUndirected(vector<vector<int>>& adj, int s, vector<bool>& visited, int parent) {
    visited[s] = true;
    for(auto &i: adj[s]) {
        if(visited[i] == false) {
            if(helperUndirected(adj, i, visited, s) == true) {
                return true;
            }
        }
        else if (i != parent) {
            return true;
        }
    }
    return false;
}
bool detectUndirectedCycle(vector<vector<int>>& adj) {
    /**
     * Time complexity: O(V + E)
     */
    int v = adj.size();
    vector<bool> visited(v, false);
    for(int i = 0; i < v; i++) {
        if(visited[i] == false) {
            if(helperUndirected(adj, i, visited, -1) == true) {
                return true;
            }
        }
    }
    return false;
}

bool helperDirected(vector<vector<int>>& adj, int s, vector<bool>& visited, vector<bool>& recursionStack) {
    visited[s] = true;
    recursionStack[s] = true;
    for(auto &i: adj[s]) {
        if(visited[i] == false && helperDirected(adj, i, visited, recursionStack) == true) {
            return true;
        }
        else if (recursionStack[i]) {
            return true;
        }
    }
    recursionStack[s] = false;
    return false;
}
bool detectDirectedCycle(vector<vector<int>>& adj) {
    /**
     * Time complexity: O(V + E)
     */
    int v = adj.size();
    vector<bool> visited(v, false);
    vector<bool> recursionStack(v, false);
    for(int i = 0; i < v; i++) {
        if(visited[i] == false) {
            if(helperDirected(adj, i, visited, recursionStack) == true) {
                return true;
            }
        }
    }
    return false;
}

int main() {
    int v = 6;
    vector<vector<int>> adj(v, vector<int>());
    addDirectedEdge(adj, 0, 1);
    addDirectedEdge(adj, 2, 1);
    addDirectedEdge(adj, 2, 3);
    addDirectedEdge(adj, 3, 4);
    addDirectedEdge(adj, 4, 5);
    addDirectedEdge(adj, 5, 3);
    cout << "Adjacency List:\n";
    printGraph(adj);
    cout << "Is there a cycle: " << detectDirectedCycle(adj) << '\n';
    return 0;
}