#include <iostream>
#include <vector>
using namespace std;

bool canPartition(vector<int>& arr, int sum) {
    vector<bool> dp(sum + 1, false);
    dp[0] = true; // Base case: We can always form sum 0

    for (int num : arr) {
        for (int j = sum; j >= num; j--) {
            if (dp[j - num]) dp[j] = true;
        }
    }
    
    return dp[sum];
}

int main() {
    int N;
    cin >> N;
    
    vector<int> arr(N);
    int totalSum = 0;

    for (int i = 0; i < N; i++) {
        cin >> arr[i];
        totalSum += arr[i];
    }

    // If total sum is odd, it's impossible to split equally
    if (totalSum % 2 != 0 || N < 2) {
        cout << 0 << endl;
        return 0;
    }

    int target = totalSum / 2;

    // Check if we can find a subset with sum = totalSum / 2
    if (canPartition(arr, target)) {
        cout << target << endl;
    } else {
        cout << 0 << endl;
    }

    return 0;
}