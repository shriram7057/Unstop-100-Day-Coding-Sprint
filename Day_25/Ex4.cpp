#include <iostream>
#include <vector>

int user_logic(int n, std::vector<int> &a, std::vector<int> &b);

int main() {
    int n;
    std::cin >> n;
    std::vector<int> a(n), b(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
        std::cin >> b[i];
    }
    int result = user_logic(n, a, b);
    std::cout << result << std::endl;
    return 0;
}

int user_logic(int n, std::vector<int> &a, std::vector<int> &b) {

    int totalMasks = 1 << n;

    std::vector<int> dp(totalMasks, 1e9);

    dp[0] = 0;

    for (int mask = 0; mask < totalMasks; mask++) {

        int i = __builtin_popcount(mask);

        if (i >= n) continue;

        for (int j = 0; j < n; j++) {

            // If b[j] is not used
            if (!(mask & (1 << j))) {

                int newMask = mask | (1 << j);

                dp[newMask] = std::min(
                    dp[newMask],
                    dp[mask] + (a[i] ^ b[j])
                );
            }
        }
    }

    return dp[totalMasks - 1];
}