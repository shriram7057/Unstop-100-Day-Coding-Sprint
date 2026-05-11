#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

bool canDivideFairly(vector<int>& arr, int k) {
    int n = arr.size();
    int totalSum = 0;
    
    for (int num : arr) totalSum += num;

    int target = totalSum / 2;
    vector<bool> dp(target + 1, false);
    dp[0] = true;

    for (int num : arr) {
        for (int j = target; j >= num; j--) {
            dp[j] = dp[j] || dp[j - num];
        }
    }

    for (int s1 = target; s1 >= 0; s1--) {
        if (dp[s1]) {
            int s2 = totalSum - s1;
            if (abs(s1 - s2) <= k) return true;
        }
    }
    
    return false;
}

int main() {
    int n, k;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];
    cin >> k;

    cout << (canDivideFairly(arr, k) ? "True" : "False") << endl;
    return 0;
}