#include <bits/stdc++.h>
using namespace std;
#define inf 1e17
typedef long long ll;

void find_cheapest_route(int n, int m, vector<tuple<int, int, int>> &toll_bridges) {
    vector<vector<pair<int,ll>>> adj(n+1), rev(n+1);
    
    for (auto &t : toll_bridges) {
        int u, v, w;
        tie(u, v, w) = t;
        adj[u].push_back({v, w});
        rev[v].push_back({u, w});
    }
    
    // Dijkstra from source (1)
    vector<ll> dist1(n+1, inf);
    priority_queue<pair<ll,int>, vector<pair<ll,int>>, greater<>> pq;
    
    dist1[1] = 0;
    pq.push({0,1});
    
    while (!pq.empty()) {
        auto [d,u] = pq.top(); pq.pop();
        if (d > dist1[u]) continue;
        
        for (auto &[v,w] : adj[u]) {
            if (dist1[v] > d + w) {
                dist1[v] = d + w;
                pq.push({dist1[v], v});
            }
        }
    }
    
    // Dijkstra from destination (n) on reversed graph
    vector<ll> dist2(n+1, inf);
    
    dist2[n] = 0;
    pq.push({0,n});
    
    while (!pq.empty()) {
        auto [d,u] = pq.top(); pq.pop();
        if (d > dist2[u]) continue;
        
        for (auto &[v,w] : rev[u]) {
            if (dist2[v] > d + w) {
                dist2[v] = d + w;
                pq.push({dist2[v], v});
            }
        }
    }
    
    ll ans = inf;
    
    // Try applying discount on each edge
    for (auto &t : toll_bridges) {
        int u, v, w;
        tie(u, v, w) = t;
        
        if (dist1[u] == inf || dist2[v] == inf) continue;
        
        ll cost = dist1[u] + (w / 2) + dist2[v];
        ans = min(ans, cost);
    }
    
    cout << ans;
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<tuple<int, int, int>> toll_bridges;
    for (int i = 0; i < m; i++) {
        int x, y, z;
        cin >> x >> y >> z;
        toll_bridges.push_back({x, y, z});
    }
    find_cheapest_route(n, m, toll_bridges);
    return 0;
}