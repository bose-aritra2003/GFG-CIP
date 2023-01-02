#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int minimumSpanningTree(int V, vector<vector<int>> adj[]) {
    /**
     * This is a Greedy Algorithm
     * Time Complexity: O(E log E)
     * Auxiliary Space: O(E)
     */
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    vector<bool> vis(V, false);
    int sum = 0; //If you have to print the MST you can keep another vector of pairs
    pq.emplace(0, 0);
    //E log E + E log E = E log E
    while(!pq.empty()) {
        //Below will take log(pq size) = log(E) which is maximum possible for pq size
        auto x = pq.top();
        pq.pop();
        int node = x.second, weight = x.first;
        if(vis[node]) {
            continue;
        }
        vis[node] = true;
        sum += weight;
        //Below loop runs for E log E times
        for(auto &i: adj[node]) {
            int adjNode = i[0], adjWt = i[1];
            if(!vis[adjNode]) {
                //log E
                pq.emplace(adjWt, adjNode);
            }
        }
    }
    return sum;
}