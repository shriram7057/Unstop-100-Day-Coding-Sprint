#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
int user_logic(int n, std::vector<int> arr) {
    const int MOD = 1e9 + 7;

    std::vector<std::pair<int, int>> v;
    for (int i = 0; i < n; i++) {
        v.push_back({arr[i], i});
    }

    std::sort(v.begin(), v.end());

    std::unordered_map<int, int> lastIndex;
    for (int i = 0; i < n; i++) {
        lastIndex[v[i].first] = i;
    }

    long long result = 0;

    for (int i = 0; i < n; i++) {
        int value = v[i].first;
        int originalIndex = v[i].second;
        int last = lastIndex[value];

        result = (result + originalIndex + last) % MOD;
    }

    return result;
}
int main() {
    int n;
    std::cin >> n;
    std::vector<int> arr(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> arr[i];
    }
    int measurement = user_logic(n, arr);
    std::cout << measurement << std::endl;
    return 0;
}