#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

void dfs(vector<vector<int>>& tree, vector<bool>& visited, int u, vector<pair<int, int>>& result) {
    visited[u] = true;
    for (int v : tree[u]) {
        if (!visited[v]) {
            result.emplace_back(min(u + 1, v + 1), max(u + 1, v + 1));
            dfs(tree, visited, v, result);
        }
    }
}

vector<pair<int, int>> bfs(vector<vector<int>>& tree, int n) {
    vector<bool> visited(n, false);
    vector<pair<int, int>> result;
    queue<int> q;
    q.push(0);
    visited[0] = true;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int v : tree[u]) {
            if (!visited[v]) {
                visited[v] = true;
                result.emplace_back(min(u + 1, v + 1), max(u + 1, v + 1));
                q.push(v);
            }
        }
    }
    return result;
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> tree(n);
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        u -= 1;
        v -= 1;
        tree[u].push_back(v);
        tree[v].push_back(u);
    }

    vector<bool> visited(n, false);
    vector<pair<int, int>> s1;
    dfs(tree, visited, 0, s1);

    vector<pair<int, int>> s2 = bfs(tree, n);

    sort(s1.begin(), s1.end());
    sort(s2.begin(), s2.end());

    for (size_t i = 0; i < s1.size(); ++i) {
        cout << s1[i].first << " " << s1[i].second << endl;
    }
    for (size_t i = 0; i < s2.size(); ++i) {
        cout << s2[i].first << " " << s2[i].second << endl;
    }

    return 0;
}