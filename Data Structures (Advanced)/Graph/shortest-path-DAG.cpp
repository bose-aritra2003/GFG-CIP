#include <iostream>
#include <vector>
#include <queue>
#include <stack>

using namespace std;

void addDirectedWeightEdge(vector<vector<pair<int, int>>>& adj, int u, int v, int w) {
    /**
     * Adds a directed edge from u to v
     */
    adj[u].push_back({v, w});
}

void printGraph(vector<vector<pair<int, int>>>& adj) {
    /**
     * Prints the adjacency list representation of the graph
     */
    for(int i = 0; i < adj.size(); i++) {
        cout << i << ": ";
        for(auto &j: adj[i]) {
            cout << j.first << ' ';
        }
        cout << '\n';
    }
}


void helper(vector<vector<pair<int, int>>>& adj, int s, vector<bool>& visited, stack<int>& st) {
    visited[s] = true;
    for(auto &i: adj[s]) {
        if(visited[i.first] == false) {
            helper(adj, i.first, visited, st);
        }
    }
    st.push(s);
}
void shortestPathDAG(vector<vector<pair<int, int>>>& adj, int s) {
    /**
     * Time complexity: O(V + E)
     */
    stack<int> st;
    int v = adj.size();
    vector<bool> visited(v, false);
    for(int i = 0; i < v; i++) {
        if(visited[i] == false) {
            helper(adj, i, visited, st);
        }
    }

    while(!st.empty() and st.top() != s) {
        st.pop();
    }
    vector<int> distance(v, INT_MAX);
    distance[s] = 0;
    while(st.empty() == false) {
        int curr = st.top();
        for(auto &i: adj[curr]) {
            int weight = i.second;
            int curr_dist = distance[curr] + weight;
            distance[i.first] = min(curr_dist, distance[i.first]);
        }
        st.pop();
    }
    for(auto &i: distance) {
        cout << i << ' ';
    }
}

int main() {
    int v = 7;
    vector<vector<pair<int, int>>> adj(v, vector<pair<int, int>>());
    addDirectedWeightEdge(adj, 6, 4, 2);
    addDirectedWeightEdge(adj, 6, 5, 3);
    addDirectedWeightEdge(adj, 5, 4, 1);
    addDirectedWeightEdge(adj, 4, 0, 3);
    addDirectedWeightEdge(adj, 4, 2, 1);
    addDirectedWeightEdge(adj, 0, 1, 2);
    addDirectedWeightEdge(adj, 2, 3, 3);
    addDirectedWeightEdge(adj, 1, 3, 1);
    cout << "Adjacency List:\n";
    printGraph(adj);
    cout << "Shortest Path in a DAG:\n";
    shortestPathDAG(adj, 6);
    return 0;
}
