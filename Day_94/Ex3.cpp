#include <iostream>
#include <string>

bool can_form_by_interleaving(const std::string& S, const std::string& T) {
    int n = S.size();
    
    // Length must match and S must be even length
    if (n % 2 != 0 || T.size() != n) return false;

    std::string A = S.substr(0, n / 2);
    std::string B = S.substr(n / 2);

    int m = n / 2;

    // dp[i][j] = can we form T[0...i+j-1] using A[0...i-1] and B[0...j-1]
    bool dp[101][101] = {false};

    dp[0][0] = true;

    for (int i = 0; i <= m; i++) {
        for (int j = 0; j <= m; j++) {
            if (i > 0 && A[i - 1] == T[i + j - 1])
                dp[i][j] |= dp[i - 1][j];
            if (j > 0 && B[j - 1] == T[i + j - 1])
                dp[i][j] |= dp[i][j - 1];
        }
    }

    return dp[m][m];
}

int main() {
    std::string S, T;
    std::cin >> S >> T;
    bool result = can_form_by_interleaving(S, T);
    std::cout << (result ? 1 : 0) << std::endl;
    return 0;
}