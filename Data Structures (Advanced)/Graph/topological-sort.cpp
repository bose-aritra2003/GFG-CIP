#include <iostream>
#include <vector>
#include <queue>
#include <stack>

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


//BFS based
vector<int> countIndegrees(vector<vector<int>>& adj) {
    /**
     * Time complexity: O(E)
     */
    int v = adj.size();
    vector<int> res(v);
    for(int i = 0; i < v; i++) {
        for(auto &j: adj[i]) {
            res[j]++;
        }
    }
    return res;
}

void helperTopoBFS(vector<vector<int>>& adj, vector<int>& in_degrees) {
    /**
     * KAHN'S ALGORITHM
     */
    queue<int> q;
    for(int i = 0; i < adj.size(); i++) {
        if(in_degrees[i] == 0) {
            q.push(i);
        }
    }
    while(q.empty() == false) {
        int front = q.front();
        q.pop();
        cout << front << ' ';
        for(auto &i: adj[front]) {
            in_degrees[i]--;
            if(in_degrees[i] == 0) {
                q.push(i);
            }
        }
    }
}

void topologicalSortBFS(vector<vector<int>>& adj) {
    /**
     * Time complexity: O(V + E)
     */
    vector<int> in_degrees = countIndegrees(adj);
    helperTopoBFS(adj, in_degrees);
}

//Application
//Cycle detection in a directed graph
bool helperCycleDetect(vector<vector<int>>& adj, vector<int>& in_degrees) {
    queue<int> q;
    int count = 0;
    for(int i = 0; i < adj.size(); i++) {
        if(in_degrees[i] == 0) {
            q.push(i);
        }
    }
    while(q.empty() == false) {
        int front = q.front();
        q.pop();
        for(auto &i: adj[front]) {
            in_degrees[i]--;
            if(in_degrees[i] == 0) {
                q.push(i);
            }
        }
        count++;
    }
    return count != adj.size();
}
bool detectCycle(vector<vector<int>>& adj) {
    vector<int> in_degrees = countIndegrees(adj);
    return helperCycleDetect(adj, in_degrees);
}

//DFS based
void helperTopoDFS(vector<vector<int>>& adj, int s, vector<bool>& visited, stack<int>& st) {
    visited[s] = true;
    for(auto &i: adj[s]) {
        if(visited[i] == false) {
            helperTopoDFS(adj, i, visited, st);
        }
    }
    st.push(s);
}
void topologicalSortDFS(vector<vector<int>>& adj) {
    /**
     * Time complexity: O(V + E)
     */
    stack<int> st;
    int v = adj.size();
    vector<bool> visited(v, false);
    for(int i = 0; i < v; i++) {
        if(visited[i] == false) {
            helperTopoDFS(adj, i, visited, st);
        }
    }
    while(st.empty() == false) {
        int item = st.top();
        st.pop();
        cout << item << ' ';
    }
}


int main() {
    int v = 5;
    vector<vector<int>> adj(v, vector<int>());
    addDirectedEdge(adj, 0, 1);
    addDirectedEdge(adj, 1, 3);
    addDirectedEdge(adj, 3, 4);
    addDirectedEdge(adj, 2, 3);
    addDirectedEdge(adj, 2, 4);
    cout << "Adjacency List:\n";
    printGraph(adj);
    cout << "Topological Sort:\n";
    topologicalSortDFS(adj);
    return 0;
}