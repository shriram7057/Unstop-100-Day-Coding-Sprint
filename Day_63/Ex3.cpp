#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int minDistance(string word1, string word2) {
    int m = word1.size(), n = word2.size();
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

    for (int i = 0; i <= m; i++) {
        for (int j = 0; j <= n; j++) {
            if (i == 0) {
                dp[i][j] = j; // Insert all characters of word2
            } else if (j == 0) {
                dp[i][j] = i; // Remove all characters of word1
            } else if (word1[i - 1] == word2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1]; // Characters match, no operation needed
            } else {
                dp[i][j] = 1 + min({dp[i - 1][j],    // Delete a character
                                    dp[i][j - 1],    // Insert a character
                                    dp[i - 1][j - 1] // Replace a character
                                   });
            }
        }
    }

    return dp[m][n];
}

int main() {
    string word1, word2;
    cin >> word1 >> word2;
    cout << minDistance(word1, word2) << endl;
    return 0;
}