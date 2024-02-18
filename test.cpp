#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

class Graph {
private:
    unordered_map<int, vector<int>> adj_list;

public:
    void add_edge(int u, int v) {
        adj_list[u].push_back(v);
    }

    void dfs(int start, unordered_set<int>& visited) {
        visited.insert(start);
        cout << start << " ";

        for (int neighbor : adj_list[start]) {
            if (visited.find(neighbor) == visited.end()) {
                dfs(neighbor, visited);
            }
        }
    }

    void dfs_util(int start) {
        unordered_set<int> visited;
        dfs(start, visited);
    }
};

int main() {
    Graph g;

    // Example usage:
    g.add_edge(0, 1);
    g.add_edge(0, 2);
    g.add_edge(1, 2);
    g.add_edge(2, 0);
    g.add_edge(2, 3);
    g.add_edge(3, 3);

    cout << "Depth First Traversal (DFS) starting from vertex 2:\n";
    g.dfs_util(2);

    return 0;
}
