#include <iostream>
#include <vector>

using namespace std;

/*
 * You can see that in all the below implementations,
 * we are resizing the arrays to x + 1 instead of x.
 * This is to make this code usable in both 0-indexed and 1-indexed graphs.
 */


//Simple Implementation
//All operations are O(n)
class DisjointSetSimple {
private:
    vector<int> parent;
public:
    DisjointSetSimple(int x) {
        parent.resize(x + 1);
        for(int i = 0; i < x; i++) {
            parent[i] = i;
        }
    }
    int find(int x) {
        if (parent[x] == x)
            return x;
        return parent[x] = find(parent[x]);
    }
    void unionSimple(int x, int y) {
        int xRoot = find(x);
        int yRoot = find(y);
        if (xRoot == yRoot)
            return;
        parent[yRoot] = xRoot;
    }
};

//Union by Rank
//All operations are O(log(n))
class DisjointSetRank {
private:
    vector<int> parent;
    vector<int> rank;
public:
    DisjointSetRank(int x) {
        parent.resize(x + 1);
        rank.resize(x + 1, 0);
        for(int i = 0; i < x; i++) {
            parent[i] = i;
        }
    }
    int find(int x) {
        if (parent[x] == x)
            return x;
        return parent[x] = find(parent[x]);
    }
    void unionRank(int x, int y) {
        int xRoot = find(x);
        int yRoot = find(y);
        if(xRoot == yRoot)
            return;
        if(rank[xRoot] < rank[yRoot]) {
            parent[xRoot] = yRoot;
        }
        else if(rank[xRoot] > rank[yRoot]) {
            parent[yRoot] = xRoot;
        }
        else {
            parent[yRoot] = xRoot;
            rank[xRoot]++;
        }
    }
};

//Path Compression
//All operations are amortised O(1)
class DisjointSetPath {
private:
    vector<int> parent;
    vector<int> rank;
public:
    DisjointSetPath(int x) {
        parent.resize(x + 1);
        rank.resize(x + 1, 0);
        for(int i = 0; i < x; i++) {
            parent[i] = i;
        }
    }
    int findPathCompressed(int x) {
        if (parent[x] == x)
            return x;
        return parent[x] = findPathCompressed(parent[x]);
    }
    void unionRank(int x, int y) {
        int xRoot = findPathCompressed(x);
        int yRoot = findPathCompressed(y);
        if(xRoot == yRoot)
            return;
        if(rank[xRoot] < rank[yRoot]) {
            parent[xRoot] = yRoot;
        }
        else if(rank[xRoot] > rank[yRoot]) {
            parent[yRoot] = xRoot;
        }
        else {
            parent[yRoot] = xRoot;
            rank[xRoot]++;
        }
    }
};

//Union by Size (More intuitive than Union by Rank)
//Also it can be helpful to get the size of a set when needed
//All operations are O(log(n))
//You can below as a template in your programs
class DisjointSet {
private:
    vector<int> parent;
    vector<int> set_size;
public:
    explicit DisjointSet(int capacity) {
        /**
         * @brief Construct a new Disjoint Set object
         */
        parent.resize(capacity + 1);
        set_size.resize(capacity + 1, 1);
        for(int i = 0; i < capacity + 1; i++) {
            parent[i] = i;
        }
    }
    int find(int node) {
        /**
         * @brief Find the parent of the node
         * @param node: The node to find the parent of
         * @return The parent of the node
         */
        if (parent[node] == node)
            return node;
        return parent[node] = find(parent[node]);
    }
    void unite(int x, int y) {
        /**
         * @brief Unites two sets
         * @param x: first node
         * @param y: second node
         */
        int x_root = find(x);
        int y_root = find(y);
        if(x_root == y_root)
            return;
        if (set_size[x_root] < set_size[y_root]) {
            parent[x_root] = y_root;
            set_size[y_root] += set_size[x_root];
        }
        else {
            parent[y_root] = x_root;
            set_size[x_root] += set_size[y_root];
        }
    }
    int size(int node) {
        /**
         * @brief Returns the size of the set
         * @param node: The node to find the size of
         * @return: The size of the set
         */
        return set_size[find(node)];
    }
    int count() {
        /**
         * @brief Returns the number of disjoint sets
         * @return: The number of disjoint sets
         */
        int components = 0, n = parent.size();
        for(int i = 0; i < n; i++) {
            components += (find(i) == i);
        }
        return components;
    }
};