#include <iostream>
#include <vector>
#include <string>
using namespace std;

const int MOD = 1000000007;

int solve(int idx, int n, bool tight, int lastChar, int secondLastChar, const string& s, vector<vector<vector<vector<int>>>>& dp) {
    if (idx == n) return tight ? 0 : 1;
    if (dp[idx][tight][lastChar][secondLastChar] != -1) return dp[idx][tight][lastChar][secondLastChar];
    int lowerLimit = tight ? s[idx] - 'a' + 1 : 1;
    int ans = 0;
    for (int i = lowerLimit; i <= 26; i++) {
        if (i != lastChar && i != secondLastChar) {
            ans = (ans + solve(idx + 1, n, tight && (i == lowerLimit), i, lastChar, s, dp)) % MOD;
        }
    }
    dp[idx][tight][lastChar][secondLastChar] = ans;
    return ans;
}

int palindrome_phobia(int n, const string& s) {
    vector<vector<vector<vector<int>>>> dp(n, vector<vector<vector<int>>>(2, vector<vector<int>>(27, vector<int>(27, -1))));
    return solve(0, n, true, 0, 0, s, dp);
}

int main() {
    int n;
    string s;
    cin >> n >> s;
    cout << palindrome_phobia(n, s) << endl;
    return 0;
}