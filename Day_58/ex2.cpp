#include <iostream>
#include <vector>
#include <cstdlib>
#include <set>
#include <climits>
#include <algorithm>
int calculate_difference(const std::vector<int>& arr) {
    std::set<int> s;
    int maxPower = INT_MIN;

    // Store positive powers only
    for (int x : arr) {
        if (x > 0)
            s.insert(x);

        maxPower = std::max(maxPower, x);
    }

    // No valid fort to attack
    if (s.empty())
        return -1;

    int bestLength = 0;
    int bestLast = INT_MAX;

    for (int x : s) {
        // Start of sequence
        if (s.find(x - 1) == s.end()) {
            int curr = x;
            int length = 1;

            while (s.find(curr + 1) != s.end()) {
                curr++;
                length++;
            }

            // curr = last attacked fort
            if (length > bestLength) {
                bestLength = length;
                bestLast = curr;
            }
            else if (length == bestLength) {
                bestLast = std::min(bestLast, curr);
            }
        }
    }

    return abs(maxPower - (bestLast + 1));
}

int main() {
    int n;
    std::cin >> n;
    std::vector<int> arr(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> arr[i];
    }
    int result = calculate_difference(arr);
    std::cout << result << std::endl;
    return 0;
}