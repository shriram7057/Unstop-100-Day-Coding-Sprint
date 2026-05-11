#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

struct Line {
    ll m, b;       // Represents line: y = m * x + b.
    long double x; // Intersection x-coordinate with the previous line in the hull.
};

struct ConvexHull {
    deque<Line> hull;
    
    // Returns the x-coordinate of the intersection between l1 and l2.
    long double intersectX(const Line &l1, const Line &l2) {
        return (long double)(l1.b - l2.b) / (l2.m - l1.m);
    }
    
    // Adds a new line to the hull. Assumes slopes are added in order of decreasing slopes.
    void addLine(ll m, ll b) {
        Line newLine = {m, b, 0};
        while (!hull.empty()) {
            newLine.x = intersectX(hull.back(), newLine);
            if (!hull.empty() && newLine.x <= hull.back().x) {
                hull.pop_back();
            } else {
                break;
            }
        }
        if (hull.empty())
            newLine.x = -1e18;
        hull.push_back(newLine);
    }
    
    // Queries the minimum y-value at a given x (assumes queries in increasing order).
    ll query(ll x) {
        while (hull.size() >= 2 && hull[1].x <= x)
            hull.pop_front();
        return hull.front().m * x + hull.front().b;
    }
};

long long minimumCost(int N, int S, vector<int> time, vector<int> cost) {
    // Precompute prefix sums.
    vector<ll> X(N+1, 0), Y(N+1, 0);
    for (int i = 1; i <= N; i++) {
        X[i] = X[i-1] + time[i-1];
        Y[i] = Y[i-1] + cost[i-1];
    }
    
    // dp_prev[i] holds the minimum cost for washing the first i items with some number of groups.
    const ll INF = 1LL << 60;
    vector<ll> dp_prev(N+1, INF), dp_curr(N+1, INF);
    
    dp_prev[0] = 0;
    // Base case: one group for items 1..i.
    for (int i = 1; i <= N; i++) {
        dp_prev[i] = (S + X[i]) * Y[i];
    }
    
    ll ans = dp_prev[N];
    
    // Process for group counts k = 2 to N.
    for (int k = 2; k <= N; k++) {
        fill(dp_curr.begin(), dp_curr.end(), INF);
        ConvexHull cht;
        int j_index = k - 1; // The first valid index for the previous group.
        
        // Process items from i = k to N.
        for (int i = k; i <= N; i++) {
            while (j_index < i) {
                // For candidate j, our line is:
                // slope = -Y[j] and intercept = dp_prev[j] - k*S*Y[j]
                cht.addLine(-Y[j_index], dp_prev[j_index] - (ll)k * S * Y[j_index]);
                j_index++;
            }
            // Query at x = X[i].
            ll best = cht.query(X[i]);
            dp_curr[i] = (((ll)k * S + X[i]) * Y[i]) + best;
        }
        dp_prev = dp_curr;
        ans = min(ans, dp_prev[N]);
    }
    
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int N, S;
    cin >> N >> S;
    vector<int> time(N), cost(N);
    for (int i = 0; i < N; i++)
        cin >> time[i];
    for (int i = 0; i < N; i++)
        cin >> cost[i];
    
    cout << minimumCost(N, S, time, cost) << "\n";
    return 0;
}