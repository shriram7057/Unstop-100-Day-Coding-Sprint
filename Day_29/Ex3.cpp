#include <iostream>
#include <vector>
#include <functional>
using namespace std;

int sum_of_depths(int n, const vector<pair<int, int>>& edges) {
    vector<vector<int>> adj(n + 1);

    // Build adjacency list
    for (auto edge : edges) {
        int u = edge.first;
        int v = edge.second;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<bool> visited(n + 1, false);

    long long totalDepth = 0;

    // DFS function
    function<void(int, int)> dfs = [&](int node, int depth) {
        visited[node] = true;
        totalDepth += depth;

        for (int neighbor : adj[node]) {
            if (!visited[neighbor]) {
                dfs(neighbor, depth + 1);
            }
        }
    };

    dfs(1, 0);

    return totalDepth;
}

int main() {
    int n;
    cin >> n;
    vector<pair<int, int>> edges(n-1);
    for (int i = 0; i < n-1; ++i) {
        cin >> edges[i].first >> edges[i].second;
    }
    int result = sum_of_depths(n, edges);
    cout << result << endl;
    return 0;
}