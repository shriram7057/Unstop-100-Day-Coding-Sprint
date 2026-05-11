#include <iostream>
#include <vector>
using namespace std;

int minInsertions(string str) {
    int n = str.length();
    vector<vector<int>> dp(n, vector<int>(n, 0));

    // Fill DP table
    for (int len = 2; len <= n; len++) { // Substring length
        for (int i = 0; i <= n - len; i++) {
            int j = i + len - 1;
            if (str[i] == str[j])
                dp[i][j] = dp[i + 1][j - 1]; // No insertions needed
            else
                dp[i][j] = min(dp[i + 1][j], dp[i][j - 1]) + 1;
        }
    }
    
    return dp[0][n - 1];
}

int main() {
    string str;
    cin >> str;
    cout << minInsertions(str) << endl;
    return 0;
}