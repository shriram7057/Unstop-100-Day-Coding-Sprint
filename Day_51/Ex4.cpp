#include <bits/stdc++.h>
#define MOD 998244353
using namespace std;

// Function to perform modular multiplication
long long mult(long long x, long long y, long long m) {
    return (x * y) % m;
}

// Function for modular exponentiation
long long binpow(long long x, long long n, long long m) {
    if (n == 0) return 1;
    if (n & 1) {
        return mult(x, binpow(x, n - 1, m), m);
    }
    return binpow(mult(x, x, m), n / 2, m);
}

// Main function
int main() {
    long long md = 998244353;

    // Input
    long long n, d;
    cin >> n >> d;

    long long ans = 0, z = 1;

    if (d == 1) {
        ans = binpow(2, n + 1, md) - 4;
        if (ans < 0) ans += md;
        cout << ans << endl;
        return 0;
    }

    long long x = binpow(2, d - 2, md);

    for (long long i = 0; i < n; i++) {
        if (2 * (n - 1 - i) >= d) {
            if (n - 1 - i >= d) {
                ans = (ans + z * ((d + 3) * x % md)) % md;
            } else {
                ans = (ans + z * ((2 * (n - i - 1) - d + 1) * x % md)) % md;
            }
        }
        z = (z * 2) % md;
    }

    cout << (2 * ans) % md << endl;

    return 0;
}