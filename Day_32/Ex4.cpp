#include <iostream>
#include <vector>
#include <unordered_set>
int longest_tribonacci_subarray(int n, const std::vector<int>& arr) {
    std::unordered_set<int> tribonacci;

    // Generate Tribonacci numbers up to 100000
    int a = 0, b = 1, c = 1;
    tribonacci.insert(a);
    tribonacci.insert(b);
    tribonacci.insert(c);

    while (true) {
        int d = a + b + c;
        if (d > 100000)
            break;

        tribonacci.insert(d);

        a = b;
        b = c;
        c = d;
    }

    int maxLen = 0, currLen = 0;

    for (int x : arr) {
        if (tribonacci.count(x)) {
            currLen++;
            maxLen = std::max(maxLen, currLen);
        } else {
            currLen = 0;
        }
    }

    return maxLen;
}

int main() {
    int n;
    std::cin >> n;
    std::vector<int> arr(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> arr[i];
    }
    int result = longest_tribonacci_subarray(n, arr);
    std::cout << result << std::endl;
    return 0;
}