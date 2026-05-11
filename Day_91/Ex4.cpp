#include <iostream>
#include <vector>
using namespace std;

const int MOD = 998244353;
const int MAXN = 200005;

long long fact[MAXN], invfact[MAXN];

long long modexp(long long base, long long exp) {
    long long res = 1;
    while (exp) {
        if (exp & 1) res = res * base % MOD;
        base = base * base % MOD;
        exp >>= 1;
    }
    return res;
}

void init(int n) {
    fact[0] = 1;
    for (int i = 1; i <= n; i++) fact[i] = fact[i-1] * i % MOD;
    invfact[n] = modexp(fact[n], MOD-2);
    for (int i = n-1; i >= 0; i--) invfact[i] = invfact[i+1] * (i+1) % MOD;
}

int count_labeled_trees(int N, vector<int>& D) {
    long long sum = 0;
    for (int x : D) sum += x;

    if (sum != N - 1) return 0;

    init(N);

    long long ans = fact[N - 2];

    for (int i = 0; i < N; i++) {
        ans = ans * invfact[D[i]] % MOD;
    }

    ans = ans * fact[N - 1] % MOD;

    return ans;
}

int main() {
    int N;
    cin >> N;
    vector<int> D(N);
    for (int i = 0; i < N; ++i) cin >> D[i];

    cout << count_labeled_trees(N, D) << endl;
    return 0;
}