#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int minDeletionSize(vector<string>& strs) {
    int n = strs.size();
    int m = strs[0].size();
    vector<int> dp(m, 1);

    for (int j = 0; j < m; ++j) {
        for (int i = 0; i < j; ++i) {
            bool valid = true;
            for (int row = 0; row < n; ++row) {
                if (strs[row][i] > strs[row][j]) {
                    valid = false;
                    break;
                }
            }
            if (valid) {
                dp[j] = max(dp[j], dp[i] + 1);
            }
        }
    }

    int lis_length = *max_element(dp.begin(), dp.end());
    return m - lis_length;
}

int main() {
    int n;
    cin >> n;
    vector<string> strs(n);
    for (int i = 0; i < n; ++i) {
        cin >> strs[i];
    }
    cout << minDeletionSize(strs) << endl;
    return 0;
}