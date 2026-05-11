#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int minVulnerabilitySum(int N, int K, vector<int>& arr) {
    vector<int> dp(N + 1, INT_MAX);
    dp[0] = 0;  // No servers, no vulnerability

    for (int i = 1; i <= N; i++) {
        int max_val = 0;  // Track the max vulnerability in the current subarray
        for (int j = 1; j <= min(K, i); j++) {  // Consider subarrays of length up to K
            max_val = max(max_val, arr[i - j]);  // Update max vulnerability in current subarray
            dp[i] = min(dp[i], dp[i - j] + max_val);
        }
    }

    return dp[N];
}

int main() {
    int N, K;
    cin >> N >> K;
    vector<int> arr(N);
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    cout << minVulnerabilitySum(N, K, arr) << endl;
    return 0;
}