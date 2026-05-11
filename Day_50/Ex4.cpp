#include <iostream>
#include <vector>
using namespace std;

string canPartition(vector<int>& chocolates) {
    int total = 0;
    for (int c : chocolates) total += c;
    
    // If total sum is odd, partitioning is impossible
    if (total % 2 != 0) return "NO";

    int target = total / 2;
    vector<bool> dp(target + 1, false);
    dp[0] = true;

    // Subset sum DP
    for (int c : chocolates) {
        for (int j = target; j >= c; j--) {
            dp[j] = dp[j] || dp[j - c];
        }
    }
    
    return dp[target] ? "YES" : "NO";
}

int main() {
    int N;
    cin >> N;
    vector<int> chocolates(N);
    for (int i = 0; i < N; i++)
        cin >> chocolates[i];

    cout << canPartition(chocolates) << endl;
    return 0;
}