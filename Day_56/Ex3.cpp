#include <iostream>
#include <vector>

int user_logic(int n, const std::vector<int>& weights) {
    int totalNodes = (1 << (n + 1));
    
    // 1-based indexing for easier tree handling
    std::vector<int> w(totalNodes, 0);

    for (int i = 2; i < totalNodes; i++) {
        w[i] = weights[i - 2];
    }

    int ans = 0;

    // Bottom-up traversal
    for (int i = (1 << n) - 1; i >= 1; i--) {
        int left = 2 * i;
        int right = 2 * i + 1;

        int leftPath = w[left];
        int rightPath = w[right];

        ans += abs(leftPath - rightPath);

        // Propagate maximum path sum upward
        w[i] += std::max(leftPath, rightPath);
    }

    return ans;
}

int main() {
    int n;
    std::cin >> n;
    std::vector<int> weights((1 << n) - 1);
    for (int i = 0; i < weights.size(); ++i) {
        std::cin >> weights[i];
    }
    int result = user_logic(n, weights);
    std::cout << result << std::endl;
    return 0;
}