#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int calculate_max_score(int n, string s) {
    const int MOD = 1e9 + 7;

    sort(s.begin(), s.end());

    long long power = 1;
    long long ans = 0;

    for (int i = 0; i < n; i++) {
        int val = (s[i] - 'a' + 1);

        ans = (ans + (val * power) % MOD) % MOD;

        power = (power * 26) % MOD;
    }

    return (int)ans;
}

int main() {
    int n;
    string s;

    cin >> n >> s;

    int result = calculate_max_score(n, s);

    cout << result << endl;

    return 0;
}