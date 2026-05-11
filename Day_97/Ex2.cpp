#include <iostream>
#include <vector>
#include <bits/stdc++.h>
#include <climits>
using namespace std;

const int INF = INT_MAX;

int main() {
    int N, M;
    cin >> N >> M;

    vector<vector<int>> dist(N + 1, vector<int>(N + 1, INF));
    vector<vector<int>> shortestPathCount(N + 1, vector<int>(N + 1, 0));
    vector<tuple<int, int, int>> edges;

    for (int i = 1; i <= N; ++i) {
        dist[i][i] = 0;
    }

    for (int i = 0; i < M; ++i) {
        int u, v, c;
        cin >> u >> v >> c;
        edges.push_back({u, v, c});
        dist[u][v] = min(dist[u][v], c);
        dist[v][u] = min(dist[v][u], c);
    }

    for (int k = 1; k <= N; ++k) {
        for (int i = 1; i <= N; ++i) {
            for (int j = 1; j <= N; ++j) {
                if (dist[i][k] < INF && dist[k][j] < INF) {
                    if (dist[i][j] > dist[i][k] + dist[k][j]) {
                        dist[i][j] = dist[i][k] + dist[k][j];
                        shortestPathCount[i][j] = 1; // Reset because a new shortest path is found
                    } else if (dist[i][j] == dist[i][k] + dist[k][j]) {
                        shortestPathCount[i][j] = 1; // Mark edge as contributing
                    }
                }
            }
        }
    }

    int notPartOfShortestPaths = 0;

    for (const auto& edge : edges) {
        int u, v, c;
        tie(u, v, c) = edge;
        bool isInShortestPath = false;

        for (int i = 1; i <= N; ++i) {
            for (int j = 1; j <= N; ++j) {
                if (dist[i][u] < INF && dist[v][j] < INF && dist[i][j] == dist[i][u] + c + dist[v][j]) {
                    isInShortestPath = true;
                    break;
                }
            }
            if (isInShortestPath) break;
        }

        if (!isInShortestPath) {
            notPartOfShortestPaths++;
        }
    }

    cout << notPartOfShortestPaths << endl;
    return 0;
}#include <iostream>
#include <vector>
#include <bits/stdc++.h>
#include <climits>
using namespace std;

const int INF = INT_MAX;

int main() {
    int N, M;
    cin >> N >> M;

    vector<vector<int>> dist(N + 1, vector<int>(N + 1, INF));
    vector<vector<int>> shortestPathCount(N + 1, vector<int>(N + 1, 0));
    vector<tuple<int, int, int>> edges;

    for (int i = 1; i <= N; ++i) {
        dist[i][i] = 0;
    }

    for (int i = 0; i < M; ++i) {
        int u, v, c;
        cin >> u >> v >> c;
        edges.push_back({u, v, c});
        dist[u][v] = min(dist[u][v], c);
        dist[v][u] = min(dist[v][u], c);
    }

    for (int k = 1; k <= N; ++k) {
        for (int i = 1; i <= N; ++i) {
            for (int j = 1; j <= N; ++j) {
                if (dist[i][k] < INF && dist[k][j] < INF) {
                    if (dist[i][j] > dist[i][k] + dist[k][j]) {
                        dist[i][j] = dist[i][k] + dist[k][j];
                        shortestPathCount[i][j] = 1; // Reset because a new shortest path is found
                    } else if (dist[i][j] == dist[i][k] + dist[k][j]) {
                        shortestPathCount[i][j] = 1; // Mark edge as contributing
                    }
                }
            }
        }
    }

    int notPartOfShortestPaths = 0;

    for (const auto& edge : edges) {
        int u, v, c;
        tie(u, v, c) = edge;
        bool isInShortestPath = false;

        for (int i = 1; i <= N; ++i) {
            for (int j = 1; j <= N; ++j) {
                if (dist[i][u] < INF && dist[v][j] < INF && dist[i][j] == dist[i][u] + c + dist[v][j]) {
                    isInShortestPath = true;
                    break;
                }
            }
            if (isInShortestPath) break;
        }

        if (!isInShortestPath) {
            notPartOfShortestPaths++;
        }
    }

    cout << notPartOfShortestPaths << endl;
    return 0;
}