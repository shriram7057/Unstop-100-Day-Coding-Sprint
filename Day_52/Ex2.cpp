#include <iostream>
#include <vector>
#define MOD 1000000007
using namespace std;

int seat_allotment(int N) {
    // If N is odd, it's impossible to fill all seats with dominoes (each covering 2 seats).
    if(N % 2 != 0) return 0;
    
    // Let m = N/2. We will compute dp[m] using the recurrence.
    int m = N / 2;
    
    // For m = 0, which corresponds to a 3x0 board, there is exactly one tiling (the empty tiling).
    // But since N>=1, we start with m>=1. We set up our dp array for indices 0...m.
    vector<long long> dp(m+1, 0);
    dp[0] = 1;
    if(m >= 1) dp[1] = 3;
    
    // Fill dp using the recurrence: dp[i] = 4*dp[i-1] - dp[i-2]
    for (int i = 2; i <= m; i++) {
        dp[i] = (4 * dp[i-1] % MOD - dp[i-2] % MOD + MOD) % MOD; // add MOD to avoid negative results
    }
    
    return dp[m];
}

int main() {
    int N;
    cin >> N;
    cout << seat_allotment(N) << endl;
    return 0;
}