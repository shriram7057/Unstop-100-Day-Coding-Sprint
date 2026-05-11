#include <iostream>
#include <vector>
int min_difficulty(const std::vector<int>& arr, int d) {
    int n = arr.size();
    
    if (n < d) return -1; // not enough jobs

    const int INF = 1e9;
    std::vector<std::vector<int>> dp(d + 1, std::vector<int>(n + 1, INF));

    dp[0][0] = 0;

    for (int day = 1; day <= d; day++) {
        for (int i = day; i <= n; i++) {
            int maxD = 0;
            for (int j = i; j >= day; j--) {
                maxD = std::max(maxD, arr[j - 1]);
                dp[day][i] = std::min(dp[day][i], dp[day - 1][j - 1] + maxD);
            }
        }
    }

    return dp[d][n];
}
int main() {
    int B, D;
    std::cin >> B;
    std::vector<int> arr(B);
    for (int i = 0; i < B; i++) {
        std::cin >> arr[i];
    }
    std::cin >> D;
    int result = min_difficulty(arr, D);
    std::cout << result << std::endl;
    return 0;
}