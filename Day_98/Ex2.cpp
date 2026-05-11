#include <iostream>
#include <vector>
#define MOD 998244353
#define MAXN 200010
using namespace std;

long long power(long long a, long long b, long long p) {
    long long res = 1, base = a % p;
    while (b > 0) {
        if (b & 1) res = res * base % p;
        base = base * base % p;
        b >>= 1;
    }
    return res;
}

long long combination(int a, int b, vector<long long>& mul, vector<long long>& inv, long long p) {
    long long res = inv[b] * inv[a - b] % p;
    res = res * mul[a] % p;
    return res;
}

int main() {
    int n, m, k;
    cin >> n >> m >> k;

    vector<int> degree(MAXN, 0);
    vector<long long> mul(MAXN, 1), inv(MAXN, 1);

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        degree[u]++;
        degree[v]++;
    }

    int oddCount = 0;
    for (int i = 1; i <= n; i++) {
        if (degree[i] % 2 == 1) {
            oddCount++;
        }
    }

    for (int i = 1; i <= n; i++) {
        mul[i] = mul[i - 1] * i % MOD;
    }

    inv[n] = power(mul[n], MOD - 2, MOD);
    for (int i = n - 1; i >= 0; i--) {
        inv[i] = inv[i + 1] * (i + 1) % MOD;
    }

    long long result = 0;
    for (int i = 0; i <= oddCount; i += 2) {
        if (k - i > n - oddCount || k - i < 0) continue;
        long long add = combination(oddCount, i, mul, inv, MOD) 
                      * combination(n - oddCount, k - i, mul, inv, MOD) % MOD;
        result = (result + add) % MOD;
    }

    cout << result << endl;
    return 0;
}