#include <iostream>
#include <vector>
#include <queue>

using namespace std;

//Connected components are also sometimes called islands

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

//BFS solution
void processComponentBFS(vector<vector<int>>& adj, int s, vector<bool>& visited) {
    queue<int> q;
    q.push(s);
    visited[s] = true;
    while(q.empty() == false) {
        int curr = q.front();
        q.pop();
        for(auto &j: adj[curr]) {
            if(visited[j] == false) {
                visited[j] = true;
                q.push(j);
            }
        }
    }
}
int countComponentsBFS(vector<vector<int>>& adj) {
    /**
     * Time complexity: O(V + E)
     */
    int v = adj.size();
    int ans = 0;
    vector<bool> visited(v, false);
    for(int i = 0; i < v; i++) {
        if(visited[i] == false) {
            ans++;
            processComponentBFS(adj, i, visited);
        }
    }
    return ans;
}

//DFS solution
void processComponentDFS(vector<vector<int>>& adj, int s, vector<bool>& visited) {
    visited[s] = true;
    cout << s << ' ';
    for(auto &i: adj[s]) {
        if(visited[i] == false) {
            processComponentDFS(adj, i, visited);
        }
    }
}

void countComponentDFS(vector<vector<int>>& adj) {
    int v = adj.size()
    int ans = 0;
    vector<bool> visited(v, false);
    for(int i = 0; i < v; i++) {
        if(visited[i] == false) {
            ans++;
            processComponentDFS(adj, i, visited);
        }
    }
    return ans;
}

int main() {
    int v = 9;
    vector<int> adj[v];
    addUndirectedEdge(adj, 0, 1);
    addUndirectedEdge(adj, 0, 2);
    addUndirectedEdge(adj, 1, 2);
    addUndirectedEdge(adj, 3, 4);
    addUndirectedEdge(adj, 5, 6);
    addUndirectedEdge(adj, 5, 7);
    addUndirectedEdge(adj, 7, 8);
    cout << "Adjacency List:\n";
    printGraph(adj);
    cout << "No. of Connected Components: " << countComponentsBFS(adj) << '\n';
    return 0;
}