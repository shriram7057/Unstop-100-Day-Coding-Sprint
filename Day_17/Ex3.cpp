#include <iostream>
#include <vector>

int countTriplets(int n, std::vector<int>& arr) {
    const int MAX = 1 << 16;
    std::vector<int> freq(MAX, 0);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            freq[arr[i] & arr[j]]++;
        }
    }

    int count = 0;

    for (int k = 0; k < n; k++) {
        for (int mask = 0; mask < MAX; mask++) {
            if ((mask & arr[k]) == 0) {
                count += freq[mask];
            }
        }
    }

    return count;
}

int main() {
    int n;
    std::cin >> n;
    std::vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        std::cin >> arr[i];
    }
    
    int result = countTriplets(n, arr);
    std::cout << result << std::endl;
    
    return 0;
}