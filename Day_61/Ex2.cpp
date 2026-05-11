#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;

const int INF = 1e9;

void user_logic(int n, int &min_people, int &max_one_way_pairs) {
    // Special case: if n==0, no network exists.
    if(n == 0) {
        min_people = 0;
        max_one_way_pairs = 0;
        return;
    }
    
    // Precompute triangular numbers T(k)= k*(k-1)/2 for k>=2 that are <= n.
    vector<pair<int,int>> coins; // pair: {cost = k, value = T(k)}
    for (int k = 2; ; k++) {
        int val = k*(k-1)/2;
        if(val > n) break;
        coins.push_back({k, val});
    }
    
    vector<int> dp(n+1, INF);
    dp[0] = 0;
    // dp[x] = minimum total nodes to achieve exactly x mutual pairs.
    for (int x = 1; x <= n; x++) {
        for (auto &coin : coins) {
            int cost = coin.first;
            int val  = coin.second;
            if (val > x) break;
            dp[x] = min(dp[x], dp[x - val] + cost);
        }
    }
    
    min_people = dp[n];
    // Maximum one-way pairs are all pairs (ordered) minus the mutual pairs.
    // Total directed pairs among m nodes = m*(m-1)/2.
    max_one_way_pairs = (min_people*(min_people-1)/2) - n;
}

int main() {
    int n;
    cin >> n;
    int min_people, max_one_way_pairs;
    user_logic(n, min_people, max_one_way_pairs);
    cout << min_people << " " << max_one_way_pairs << endl;
    return 0;
}