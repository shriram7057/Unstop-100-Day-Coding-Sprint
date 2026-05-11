#include <iostream>
#include <vector>
using namespace std;

string can_divide_into_groups(int n, vector<pair<int, int>>& cards) {
    vector<vector<int>> adj(n + 1);
    vector<int> degree(n + 1, 0);

    for (auto &card : cards) {
        int u = card.first;
        int v = card.second;

        // Same numbers on a card not allowed
        if (u == v)
            return "NO";

        adj[u].push_back(v);
        adj[v].push_back(u);

        degree[u]++;
        degree[v]++;

        // A number cannot appear more than twice
        if (degree[u] > 2 || degree[v] > 2)
            return "NO";
    }

    // Check bipartite graph
    vector<int> color(n + 1, -1);

    for (int i = 1; i <= n; i++) {
        if (color[i] == -1) {
            vector<int> q;
            q.push_back(i);
            color[i] = 0;

            for (int j = 0; j < q.size(); j++) {
                int u = q[j];

                for (int v : adj[u]) {
                    if (color[v] == -1) {
                        color[v] = color[u] ^ 1;
                        q.push_back(v);
                    }
                    else if (color[v] == color[u]) {
                        return "NO";
                    }
                }
            }
        }
    }

    return "YES";
}

int main() {
    int t;
    cin >> t;
    
    while (t--) {
        int n;
        cin >> n;
        
        vector<pair<int, int>> cards(n);
        for (int i = 0; i < n; ++i) {
            cin >> cards[i].first >> cards[i].second;
        }
        
        // Call user logic function and print the result
        cout << can_divide_into_groups(n, cards) << endl;
    }
    
    return 0;
}