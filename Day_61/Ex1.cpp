#include <iostream>
#include <vector>
using namespace std;
 
const int MOD = 1000000007;
 
// Fast exponentiation modulo MOD
long long modexp(long long base, int exp) {
    long long res = 1;
    while(exp > 0) {
        if(exp & 1)
            res = (res * base) % MOD;
        base = (base * base) % MOD;
        exp >>= 1;
    }
    return res;
}
 
// Modular inverse using Fermat's little theorem (MOD is prime)
long long modinv(long long a) {
    return modexp(a, MOD - 2);
}
 
int count_distinct_network_designs(int N, int K) {
    int n = N - 1; // number of star-edges (departments 2..N)
    
    // Precompute factorials and inverse factorials up to n.
    vector<long long> fact(n+1), invfact(n+1);
    fact[0] = 1;
    for (int i = 1; i <= n; i++)
        fact[i] = (fact[i-1] * i) % MOD;
    invfact[n] = modinv(fact[n]);
    for (int i = n - 1; i >= 0; i--)
        invfact[i] = (invfact[i+1] * (i+1)) % MOD;
 
    // dp[i][j] : using values 1..i (i.e. cost values from i to K, with base = K-i+1)
    // and a total count of j among the star-edges.
    vector<vector<long long>> dp(K+1, vector<long long>(n+1, 0));
    dp[0][0] = 1;
 
    // Process cost groups 1,2,...,K.
    for (int i = 1; i <= K; i++) {
        int base = K - i + 1; // base factor for group i
        for (int j = 0; j <= n; j++) {
            if(dp[i-1][j] == 0) continue;
            // r is the number of star-edges with cost equal to i.
            for (int r = 0; r <= n - j; r++) {
                // The contribution from group i is:
                //    (K-i+1)^( r*j + binom(r,2) ) / r!
                int exp = r * j + (r * (r - 1)) / 2;
                long long term = modexp(base, exp);
                term = (term * invfact[r]) % MOD;
                dp[i][j+r] = (dp[i][j+r] + dp[i-1][j] * term) % MOD;
            }
        }
    }
 
    // Multiply by (N-1)! to account for the multinomial coefficient
    long long ans = (fact[n] * dp[K][n]) % MOD;
    return (int)ans;
}
 
int main() {
    int N, K;
    cin >> N >> K;
    cout << count_distinct_network_designs(N, K) << endl;
    return 0;
}