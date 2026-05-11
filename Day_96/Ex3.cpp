#include <iostream>
#include <vector>
#include <string>

using namespace std;

const int MOD = 1e9 + 7;

int countPlusMinusSequences(const string& S) {
    int n = S.size();
    vector<int> prev(n + 1, 0);
    vector<int> curr(n + 1, 0);
    prev[0] = 1; // Base case: one way to arrange a sequence of length 1

    for (int i = 1; i <= n; ++i) {
        vector<int> prefixSum(n + 2, 0);

        // Compute prefix sums for the previous state
        for (int j = 0; j < i; ++j) {
            prefixSum[j + 1] = (prefixSum[j] + prev[j]) % MOD;
        }

        // Compute current state using prefix sums
        for (int j = 0; j <= i; ++j) {
            if (S[i - 1] == '+') {
                curr[j] = (j > 0 ? prefixSum[j] : 0); // Sum from 0 to j-1
            } else { // S[i-1] == '-'
                curr[j] = (prefixSum[i] - prefixSum[j] + MOD) % MOD; // Sum from j to i-1
            }
        }

        // Update prev for the next iteration
        prev = curr;
    }

    // Sum up all values in the last state
    int result = 0;
    for (int val : prev) {
        result = (result + val) % MOD;
    }

    return result;
}

int main() {
    string S;
    cin >> S;

    cout << countPlusMinusSequences(S) << endl;
    return 0;
}