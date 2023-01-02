#include <iostream>
#include <vector>
#include <queue>
#include <set>

using namespace std;

vector<int> dijkstraPriorityQueue(vector<vector<pair<int, int>>>& adj, int src) {
    /**
     * Time complexity: O(E log V)
     */
    //Pair stores {weight, vertex}
    int v = adj.size();
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    vector<int> dist(v, INT_MAX);
    dist[src] = 0;
    pq.push({0, src});
    while(!pq.empty()) {
        auto p = pq.top();
        pq.pop();
        int vertex = p.second, weight = p.first;
        for(auto &u: adj[vertex]) {
            int adjVertex = u.second, adjWeight = u.first;
            if(dist[adjVertex] > weight + adjWeight) {
                dist[adjVertex] = weight + adjWeight;
                pq.push({dist[adjVertex], adjVertex});
            }
        }
    }
    return dist;
}

vector<int> dijkstraSet(vector<vector<pair<int, int>>>& adj, int src) {
    int v = adj.size();
    set<pair<int, int>> pq;
    vector<int> dist(v, INT_MAX);
    dist[src] = 0;
    pq.insert({0, src});
    while(!pq.empty()) {
        auto p = *pq.begin();
        pq.erase(p);
        int vertex = p.second, weight = p.first;
        for(auto &u: adj[vertex]) {
            int adjVertex = u.second, adjWeight = u.first;
            if(dist[adjVertex] > weight + adjWeight) {
                if(dist[adjVertex] != INT_MAX) {
                    //This is the only extra step in set implementation
                    //Now this can be considered as an optimisation in some cases
                    //Since we are saving on future iterations over unnecessary elements
                    //Suppose if we have {1, 2} now and set already has {2, 3}
                    //Then obviously {2, 3} doesn't make sense anymore, since {1, 2} is shorter
                    //However you should also remember that erase operation in set is O(log n)
                    pq.erase({dist[adjVertex], adjVertex});
                }
                dist[adjVertex] = weight + adjWeight;
                pq.insert({dist[adjVertex], adjVertex});
            }
        }
    }
    return dist;
}