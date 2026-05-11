#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    string S, query;
    cin >> S >> query;

    int n = S.size();
    int m = query.size();

    // dp[i][j] = number of ways to form query[0..j-1] using S[0..i-1]
    vector<vector<long long>> dp(n + 1, vector<long long>(m + 1, 0));

    // Empty query can be formed in 1 way
    for (int i = 0; i <= n; i++) {
        dp[i][0] = 1;
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (S[i - 1] == query[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
            } else {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }

    cout << dp[n][m] << endl;
    return 0;
}