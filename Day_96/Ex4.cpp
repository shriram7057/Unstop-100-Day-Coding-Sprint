#include <bits/stdc++.h>
using namespace std;

const int MOD = 1000000007;
const int MAX_GIFTS = 201;
const int MAX_FRIENDS = 15;

int dp[MAX_GIFTS][1 << MAX_FRIENDS];
vector<int> arr[MAX_GIFTS];

int helper(int n, int gift, int mask) {
    if (__builtin_popcount(mask) == n) return 1;
    if (gift >= MAX_GIFTS) return 0;
    if (dp[gift][mask] != -1) return dp[gift][mask];
    
    int ans = helper(n, gift + 1, mask);
    
    for (int i : arr[gift]) {
        if (mask & (1 << i)) continue;
        ans = (ans + helper(n, gift + 1, mask | (1 << i))) % MOD;
    }
    
    return dp[gift][mask] = ans;
}

void solve() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n;
    cin >> n;
    
    for (int i = 0; i < MAX_GIFTS; i++) arr[i].clear();
    memset(dp, -1, sizeof(dp));
    
    for (int i = 0; i < n; i++) {
        int k;
        cin >> k;
        for (int j = 0; j < k; j++) {
            int x;
            cin >> x;
            arr[x].push_back(i);
        }
    }
    
    cout << helper(n, 1, 0) << "\n";
}

int main() {
    solve();
    return 0;
}