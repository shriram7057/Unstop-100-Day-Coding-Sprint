#include <iostream>
#include <vector>

using namespace std;

// Placeholder logic function
int user_logic(int N, int X, const vector<int>& prices, const vector<int>& durations) {
    vector<int> dp(X + 1, 0);

    for (int i = 0; i < N; i++) {
        for (int w = X; w >= prices[i]; w--) {
            dp[w] = max(dp[w], dp[w - prices[i]] + durations[i]);
        }
    }

    return dp[X];
}
int main() {
    int N, X;
    cin >> N >> X;

    vector<int> prices(N);
    vector<int> durations(N);

    // Read the prices
    for (int i = 0; i < N; ++i) {
        cin >> prices[i];
    }

    // Read the durations
    for (int i = 0; i < N; ++i) {
        cin >> durations[i];
    }

    // Call user logic function
    int result = user_logic(N, X, prices, durations);

    // Print the result
    cout << result << endl;

    return 0;
}