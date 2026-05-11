#include <iostream>
#include <vector>
using namespace std;

string predictWinner(vector<int>& balls) {
    int N = balls.size();
    vector<vector<int>> dp(N, vector<int>(N, 0));

    // Base Case: Single element
    for (int i = 0; i < N; i++)
        dp[i][i] = balls[i];

    // DP: Filling the table diagonally
    for (int len = 2; len <= N; len++) { // Length of the subarray
        for (int i = 0; i <= N - len; i++) {
            int j = i + len - 1;
            dp[i][j] = max(balls[i] - dp[i + 1][j], balls[j] - dp[i][j - 1]);
        }
    }

    // Aryan wins if he has non-negative score difference
    return dp[0][N - 1] >= 0 ? "Aryan" : "Ankit";
}

int main() {
    int N;
    cin >> N;
    vector<int> balls(N);
    for (int i = 0; i < N; i++)
        cin >> balls[i];

    cout << predictWinner(balls) << endl;
    return 0;
}