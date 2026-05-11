#include <iostream>
#include <vector>
#include <iostream>
#include <vector>
#include <functional>
using namespace std;

void count_removable_vertices(int n, vector<pair<int, int>> edges) {
    vector<vector<int>> adj(n + 1);

    for (auto &e : edges) {
        int u = e.first;
        int v = e.second;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<vector<int>> dp(n + 1, vector<int>(2, 0));

    function<void(int, int)> dfs = [&](int u, int parent) {
        for (int v : adj[u]) {
            if (v == parent) continue;

            dfs(v, u);

            dp[u][0] += max(dp[v][0], dp[v][1]);
        }

        for (int v : adj[u]) {
            if (v == parent) continue;

            dp[u][1] = max(
                dp[u][1],
                1 + dp[v][0] +
                (dp[u][0] - max(dp[v][0], dp[v][1]))
            );
        }
    };

    dfs(1, -1);

    int maxMatching = max(dp[1][0], dp[1][1]);

    int answer = 0;

    for (int removeNode = 1; removeNode <= n; removeNode++) {

        vector<vector<int>> newAdj(n + 1);

        for (auto &e : edges) {
            int u = e.first;
            int v = e.second;

            if (u == removeNode || v == removeNode)
                continue;

            newAdj[u].push_back(v);
            newAdj[v].push_back(u);
        }

        vector<vector<int>> ndp(n + 1, vector<int>(2, 0));
        vector<int> visited(n + 1, 0);

        function<void(int, int)> solve = [&](int u, int parent) {
            visited[u] = 1;

            for (int v : newAdj[u]) {
                if (v == parent) continue;

                solve(v, u);

                ndp[u][0] += max(ndp[v][0], ndp[v][1]);
            }

            for (int v : newAdj[u]) {
                if (v == parent) continue;

                ndp[u][1] = max(
                    ndp[u][1],
                    1 + ndp[v][0] +
                    (ndp[u][0] - max(ndp[v][0], ndp[v][1]))
                );
            }
        };

        int currentMatching = 0;

        for (int i = 1; i <= n; i++) {
            if (i == removeNode || visited[i]) continue;

            solve(i, -1);

            currentMatching += max(ndp[i][0], ndp[i][1]);
        }

        if (currentMatching == maxMatching)
            answer++;
    }

    cout << answer << endl;
}

int main() {
    int n;
    cin >> n;
    vector<pair<int, int>> edges;
    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        edges.push_back(make_pair(u, v));
    }
    count_removable_vertices(n, edges);
    return 0;
}