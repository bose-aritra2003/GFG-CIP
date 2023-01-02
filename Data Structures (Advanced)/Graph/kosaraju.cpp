#include <iostream>
#include <vector>

using namespace std;

//Kosaraju's Algorithm

void DFS(vector<vector<int>> &graph, vector<bool> &visited, int v, vector<int> &st) {
    visited[v] = true;
    for(auto &u : graph[v]) {
        if(!visited[u]) {
            DFS(graph, visited, u, st);
        }
    }
    st.push_back(v);
}

void revDFS(vector<vector<int>> &transpose, vector<bool> &visited, int v) {
    cout << v << " ";
    visited[v] = true;
    for(auto &u : transpose[v]) {
        if(!visited[u]) {
            revDFS(transpose, visited, u);
        }
    }
}

void kosarajuAlgorithm(vector<vector<int>> &graph) {
    /**
     * Time Complexity: O(V + E)
     * Auxiliary Space: O(V + E)
     */

    //STEP 1
    vector<bool> visited(graph.size(), false);
    vector<int> st;
    for(int i = 0; i < graph.size(); i++) {
        if(!visited[i]) {
            DFS(graph, visited, i, st);
        }
    }

    //STEP 2
    vector<vector<int>> transpose(graph.size());
    for(int i = 0; i < graph.size(); i++) {
        for(auto &u : graph[i]) {
            transpose[u].push_back(i);
        }
    }
    visited.assign(graph.size(), false);

    //STEP 3
    while(!st.empty()) {
        int v = st.back();
        st.pop_back();
        if(!visited[v]) {
            revDFS(transposeGraph, visited, v);
            cout << endl;
        }
    }
}
