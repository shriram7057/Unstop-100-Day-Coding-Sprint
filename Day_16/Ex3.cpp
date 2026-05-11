#include <iostream>
#include <vector>
int find_winner(const std::vector<int>& arr) {
    const int OFFSET = 10000;
    const int SIZE = 20001;

    std::vector<int> freq(SIZE, 0);

    for (int num : arr) {
        freq[num + OFFSET]++;
    }

    for (int num : arr) {
        if (freq[num + OFFSET] == 1) {
            return num;
        }
    }

    return 0;
}
int main() {
    int n;
    std::cin >> n;
    std::vector<int> arr(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> arr[i];
    }
    int result = find_winner(arr);
    std::cout << result << std::endl;
    return 0;
}