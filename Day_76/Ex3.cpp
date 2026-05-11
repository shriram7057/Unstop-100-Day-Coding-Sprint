#include <iostream>
#include <vector>
using namespace std;

const long long MOD = 1000000007;

long long countFavorableSequences(long long N, long long K, long long L, long long R) {
    long long possibleValues = R - L + 1;
    vector<vector<vector<long long>>> dp(N + 1, vector<vector<long long>>(N + 1, vector<long long>(possibleValues + 1, 0)));

    for (long long i = 0; i < possibleValues; ++i) {
        dp[1][0][i] = 1;
    }

    for (long long length = 1; length < N; ++length) {
        for (long long k = 0; k < length; ++k) {
            for (long long maxValue = 0; maxValue < possibleValues; ++maxValue) {
                if (dp[length][k][maxValue] == 0) {
                    continue;
                }
                for (long long newValue = 0; newValue < possibleValues; ++newValue) {
                    if (newValue > maxValue) {
                        dp[length + 1][k + 1][newValue] = (dp[length + 1][k + 1][newValue] + dp[length][k][maxValue]) % MOD;
                    } else {
                        dp[length + 1][k][maxValue] = (dp[length + 1][k][maxValue] + dp[length][k][maxValue]) % MOD;
                    }
                }
            }
        }
    }

    long long result = 0;
    for (long long k = K; k <= N; ++k) {
        for (long long maxValue = 0; maxValue < possibleValues; ++maxValue) {
            result = (result + dp[N][k][maxValue]) % MOD;
        }
    }

    return result;
}

int main() {
    long long N, K, L, R;
    cin >> N >> K >> L >> R;
    cout << countFavorableSequences(N, K, L, R) << endl;
    return 0;
}