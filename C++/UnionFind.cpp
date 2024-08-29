#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class UnionFind {
public:
    UnionFind() {}
    
    int find(int x) {
        if (parent.find(x) == parent.end()) {
            parent[x] = x;
            rank[x] = 1;
            count++;
        }
        if (parent[x] != x) {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }
    
    void unite(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);
        if (rootX != rootY) {
            if (rank[rootX] > rank[rootY]) {
                parent[rootY] = rootX;
            } else if (rank[rootX] < rank[rootY]) {
                parent[rootX] = rootY;
            } else {
                parent[rootY] = rootX;
                rank[rootX]++;
            }
            count--;
        }
    }
    
    int getCount() {
        return count;
    }
    
private:
    unordered_map<int, int> parent;
    unordered_map<int, int> rank;
    int count = 0;
};