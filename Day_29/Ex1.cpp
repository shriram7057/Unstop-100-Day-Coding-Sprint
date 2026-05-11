#include <iostream>
#include <vector>

int find_snoop_day_index(int n, std::vector<int>& arr) {
    long long total = 0;

    // Calculate total distance
    for (int x : arr) {
        total += x;
    }

    long long curr = 0;

    // Find first day where cumulative distance
    // is at least half of total distance
    for (int i = 0; i < n; ++i) {
        curr += arr[i];

        if (curr * 2 >= total) {
            return i + 1; // 1-based index
        }
    }

    return -1;
}

int main() {
    int n;
    std::cin >> n;
    std::vector<int> arr(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> arr[i];
    }
    int result = find_snoop_day_index(n, arr);
    std::cout << result << std::endl;
    return 0;
}