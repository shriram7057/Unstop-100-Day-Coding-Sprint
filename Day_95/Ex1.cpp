#include <iostream>
#include <vector>

#include <algorithm>
using namespace std;

struct DSU {
    vector<int> parent, rank;
    DSU(int n) {
        parent.resize(n + 1);
        rank.resize(n + 1, 0);
        for (int i = 1; i <= n; i++) parent[i] = i;
    }
    int find(int x) {
        if (parent[x] != x)
            parent[x] = find(parent[x]);
        return parent[x];
    }
    void unite(int x, int y) {
        int px = find(x), py = find(y);
        if (px == py) return;
        if (rank[px] < rank[py]) parent[px] = py;
        else if (rank[px] > rank[py]) parent[py] = px;
        else {
            parent[py] = px;
            rank[px]++;
        }
    }
};

void user_logic(int N, int M, const vector<tuple<int, int, int>>& edges) {
    vector<tuple<long long, int, int>> transformed;
    long long totalPositive = 0;

    for (auto &e : edges) {
        int u, v, w;
        tie(u, v, w) = e;

        if (w > 0) totalPositive += w;

        // cost to KEEP edge
        long long cost = max(0, w);
        transformed.push_back({cost, u, v});
    }

    // Kruskal (MST)
    sort(transformed.begin(), transformed.end());

    DSU dsu(N);
    long long mstCost = 0;

    for (auto &e : transformed) {
        long long cost;
        int u, v;
        tie(cost, u, v) = e;

        if (dsu.find(u) != dsu.find(v)) {
            dsu.unite(u, v);
            mstCost += cost;
        }
    }

    // max reward = total positive edges - cost of edges we must keep
    cout << (totalPositive - mstCost) << endl;
}

int main() {
    int N, M;
    std::cin >> N >> M;
    std::vector<std::tuple<int, int, int>> edges(M);
    for (int i = 0; i < M; ++i) {
        int Ai, Bi, Ci;
        std::cin >> Ai >> Bi >> Ci;
        edges[i] = std::make_tuple(Ai, Bi, Ci);
    }
    user_logic(N, M, edges);
    return 0;
}