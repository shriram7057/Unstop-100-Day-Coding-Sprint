#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int maximizeNutritionalValue(int n, int m, int k, vector<int> &price, vector<int> &nutrition) {
    // Create a DP table: dp[couponUsed][moneySpent]
    // Initialize with -1 to denote unreachable states.
    vector<vector<int>> dp(k+1, vector<int>(m+1, -1));
    dp[0][0] = 0;
    
    for (int i = 0; i < n; i++) {
        int p = price[i];
        int nut = nutrition[i];
        int discounted = p / 2; // floor division

        // Update the dp table in reverse to ensure each fruit is considered only once.
        for (int used = k; used >= 0; used--) {
            for (int cost = m; cost >= 0; cost--) {
                if (dp[used][cost] == -1) continue;
                
                // Option 1: Buy fruit i at full price
                if (cost + p <= m) {
                    dp[used][cost + p] = max(dp[used][cost + p], dp[used][cost] + nut);
                }
                
                // Option 2: Buy fruit i with a discount coupon (if available)
                if (used < k && cost + discounted <= m) {
                    dp[used+1][cost + discounted] = max(dp[used+1][cost + discounted], dp[used][cost] + nut);
                }
            }
        }
    }
    
    // Find the maximum nutritional value achievable under the budget
    int answer = 0;
    for (int used = 0; used <= k; used++) {
        for (int cost = 0; cost <= m; cost++) {
            answer = max(answer, dp[used][cost]);
        }
    }
    
    return answer;
}

int main() {
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> price(n), nutrition(n);
    
    for (int i = 0; i < n; i++) {
        cin >> price[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> nutrition[i];
    }
    
    int result = maximizeNutritionalValue(n, m, k, price, nutrition);
    cout << result << endl;
    return 0;
}