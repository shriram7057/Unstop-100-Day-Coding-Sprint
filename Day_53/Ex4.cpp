#include <iostream>
#include <vector>
using namespace std;

const int MOD = 1000000007;
const int MAXN = 4008;

int main() {
    int n;
    cin >> n;

    vector<int> a(MAXN, 0); // Array to hold the values
    vector<vector<int>> f(MAXN, vector<int>(MAXN, 0)); // DP table
    vector<int> sum(MAXN, 0); // Cumulative sums

    // Read the elements and initialize the array
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }

    // Initialize DP table and cumulative sum
    f[1][1] = 1;  // One subsequence ending at the first element
    sum[1] = 1;   // Cumulative sum for the first element

    // Process the array
    for (int i = 2; i <= n; ++i) {
        for (int j = 1; j <= i; ++j) {
            if (a[i] > a[i - 1]) {
                f[i][j] = sum[j - 1]; // Current element is greater, extend all subsequences
            } else if (a[i] < a[i - 1]) {
                f[i][j] = (sum[i - 1] - sum[j - 1] + MOD) % MOD; // Handle strictly decreasing
            } else {
                f[i][j] = sum[i - 1]; // Handle equal elements
            }
        }

        // Update cumulative sum
        for (int j = 1; j <= i; ++j) {
            sum[j] = (sum[j - 1] + f[i][j]) % MOD;
        }
    }

    // Final answer: Sum of all subsequences ending at the last element
    int ans = 0;
    for (int i = 1; i <= n; ++i) {
        ans = (ans + f[n][i]) % MOD;
    }

    // Output the final result
    cout << ans << endl;

    return 0;
}