#include <iostream>
#include <vector>
using namespace std;
const int MOD = 998244353;

int countValidNumbers(int N) {
    vector<int> dp_prev(10, 0), dp_curr(10, 0);

    // Base case: One-digit numbers
    for (int d = 1; d <= 9; d++) {
        dp_prev[d] = 1;
    }

    // Compute DP iteratively
    for (int i = 2; i <= N; i++) {
        fill(dp_curr.begin(), dp_curr.end(), 0);
        for (int d = 1; d <= 9; d++) {
            dp_curr[d] = dp_prev[d];
            if (d > 1) dp_curr[d] = (dp_curr[d] + dp_prev[d - 1]) % MOD;
            if (d < 9) dp_curr[d] = (dp_curr[d] + dp_prev[d + 1]) % MOD;
        }
        dp_prev = dp_curr;
    }

    // Compute result
    int result = 0;
    for (int d = 1; d <= 9; d++) {
        result = (result + dp_prev[d]) % MOD;
    }

    return result;
}

int main() {
    int N;
    cin >> N;
    cout << countValidNumbers(N) << endl;
    return 0;
}