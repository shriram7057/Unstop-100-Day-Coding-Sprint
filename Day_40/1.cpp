#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, K;
    cin >> N >> K;
    
    vector<int> moves(K);
    for (int i = 0; i < K; i++) {
        cin >> moves[i];
    }

    vector<int> dp(N + 1, 0);

    for (int i = 1; i <= N; i++) {
        for (int move : moves) {
            if (move <= i) {
                dp[i] = max(dp[i], i - dp[i - move]);
            }
        }
    }

    cout << dp[N] << endl;
    return 0;
}