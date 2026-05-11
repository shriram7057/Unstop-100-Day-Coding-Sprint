#include <iostream>
#include <vector>
#include <set>
#include <functional>

using namespace std;

// Function to count valid numbers
int count_divisible_combinations(int K, int N, vector<int>& arr) {
    set<int> uniqueNumbers;

    function<void(int, int, vector<bool>&)> backtrack = [&](int current, int length, vector<bool>& used) {
        // Check only non-empty numbers
        if (length > 0 && current % K == 0) {
            uniqueNumbers.insert(current);
        }

        for (int i = 0; i < N; i++) {
            if (!used[i]) {
                used[i] = true;
                backtrack(current * 10 + arr[i], length + 1, used);
                used[i] = false;
            }
        }
    };

    vector<bool> used(N, false);
    backtrack(0, 0, used);

    return uniqueNumbers.size();
}

int main() {
    int K;
    cin >> K;

    int N;
    cin >> N;

    vector<int> arr(N);
    for (int i = 0; i < N; ++i) {
        cin >> arr[i];
    }

    int result = count_divisible_combinations(K, N, arr);
    cout << result << endl;

    return 0;
}