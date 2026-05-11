#include <iostream>
#include <vector>
using namespace std;

const int MAX = 100000 + 1;
vector<pair<int, int>> adj[MAX + MAX + 1];

// Maps the index to the corresponding index in the adjacency list
inline int f(int i) {
    return i + MAX;
}

// Adds an edge to the adjacency list
void addedge(int i, int j, int weight) {
    adj[f(i)].emplace_back(j, weight);
    adj[f(j)].emplace_back(i, weight);
}

int main() {
    int n;
    cin >> n;

    // Add edges between i and all its multiples less than or equal to n
    for (int i = 2; i <= n; ++i) {
        for (int j = i + i; j <= n; j += i) {
            int weight = j / i;  // Weight of the edge is j/i
            addedge(i, j, weight);
            addedge(i, -j, weight);
            addedge(-i, j, weight);
            addedge(-i, -j, weight);
        }
    }

    long long ans = 0;

    // Loop through all values of i from 2 to n
    for (int i = 2; i <= n; ++i) {
        // Loop through all edges connected to i
        for (const auto& element : adj[f(i)]) {
            ans += element.second;
        }
    }

    cout << ans << endl;
    return 0;
}