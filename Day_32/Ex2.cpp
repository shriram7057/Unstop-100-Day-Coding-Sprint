#include <iostream>
#include <vector>

void user_logic(int n, std::vector<int>& arr) {
    std::vector<int> freq(100001, 0);

    int maxi = 0;

    // Count frequency
    for (int x : arr) {
        freq[x]++;
        if (freq[x] > maxi)
            maxi = freq[x];
    }

    // Print teams with maximum frequency
    for (int i = 1; i <= 100000; i++) {
        if (freq[i] == maxi) {
            std::cout << i << std::endl;
        }
    }
}
int main() {
    int n;
    std::cin >> n;
    std::vector<int> arr(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> arr[i];
    }
    user_logic(n, arr);
    return 0;
}