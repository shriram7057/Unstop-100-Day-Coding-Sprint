#include <iostream>
#include <vector>
using namespace std;

const long long MOD = 1000000007;
const int N = 505;

long long add(long long x, long long y) {
    return (x + y) % MOD;
}

long long mul(long long x, long long y) {
    return (x * y) % MOD;
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<long long>> c(N, vector<long long>(N, 0));
    vector<vector<long long>> dp(N, vector<long long>(m + 1, 0));

    for (int i = 0; i < N; ++i) {
        c[i][0] = c[i][i] = 1;
        for (int j = 1; j < i; ++j) {
            c[i][j] = add(c[i - 1][j], c[i - 1][j - 1]);
        }
    }

    dp[n][0] = 1;

    for (int i = n; i > 1; --i) {
        for (int j = 0; j < m; ++j) {
            if (dp[i][j] == 0) continue;

            long long pw = 1;
            int nj = min(m, j + i - 1);

            for (int k = i; k >= 0; --k) {
                dp[k][nj] = add(dp[k][nj], mul(dp[i][j], mul(c[i][k], pw)));
                pw = mul(pw, nj - j);
            }
        }
    }

    long long ans = 0;
    for (int i = 0; i <= m; ++i) {
        ans = add(ans, dp[0][i]);
    }

    cout << ans << endl;
    return 0;
}