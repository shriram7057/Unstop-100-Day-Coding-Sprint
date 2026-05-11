#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Function to calculate the maximum number of indices you can visit starting from index i
int dfs(int i, vector<int>& arr, vector<int>& dp, int d) {
    if (dp[i] != -1) return dp[i]; // If already calculated, return the stored result
    
    int n = arr.size();
    int max_visited = 1; // Start with the current index as the first one visited
    
    // Jump to the right
    for (int j = i + 1; j <= min(i + d, n - 1) && arr[i] > arr[j]; ++j) {
        max_visited = max(max_visited, 1 + dfs(j, arr, dp, d));
    }

    // Jump to the left
    for (int j = i - 1; j >= max(i - d, 0) && arr[i] > arr[j]; --j) {
        max_visited = max(max_visited, 1 + dfs(j, arr, dp, d));
    }

    return dp[i] = max_visited; // Store and return the result
}

int main() {
    int n, d;
    cin >> n >> d;
    
    vector<int> arr(n);
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
    
    vector<int> dp(n, -1); // Initialize the DP array with -1
    
    int max_result = 0;
    
    // Iterate over each index and calculate the maximum number of indices that can be visited
    for (int i = 0; i < n; ++i) {
        max_result = max(max_result, dfs(i, arr, dp, d));
    }
    
    cout << max_result << endl;
    
    return 0;
}