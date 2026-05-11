#include <bits/stdc++.h>
using namespace std;

bool canBoltWin(int N) {
    vector<bool> dp(N + 1, false); // dp[i] = true means Bolt can win
    
    for (int i = 1; i <= N; i++) {
        for (int k = 1; k * k <= i; k++) {
            if (!dp[i - k * k]) {
                dp[i] = true;
                break;
            }
        }
    }
    return dp[N];
}

int main() {
    int N;
    cin >> N;
    cout << (canBoltWin(N) ? "True" : "False") << endl;
    return 0;
}