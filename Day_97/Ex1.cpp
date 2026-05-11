#include <iostream>
#include <vector>
#include <algorithm>
#include<bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

// Function to calculate Fibonacci using iterative DP
int fibonacci(int n) {
    if (n == 0) return 0;
    if (n == 1) return 1;

    int a = 0, b = 1, c;
    for (int i = 2; i <= n; ++i) {
        c = (a + b) % MOD;
        a = b;
        b = c;
    }
    return b;
}

// Helper function to check if partitioning is possible with the given max sum
bool isPossible(const vector<int>& arr, int K, int maxSum) {
    int currentSum = 0, partitions = 1;
    for (int num : arr) {
        if (currentSum + num > maxSum) {
            partitions++;
            currentSum = num;
            if (partitions > K) return false;
        } else {
            currentSum += num;
        }
    }
    return true;
}

int main() {
    int N, K;
    cin >> N >> K;

    vector<int> arr(N);
    for (int i = 0; i < N; ++i) {
        cin >> arr[i];
        arr[i] = abs(arr[i] - i); // Step 1: Replace each element
    }

    // Step 2: Minimize the maximum sum of partitions
    int low = *max_element(arr.begin(), arr.end());
    int high = accumulate(arr.begin(), arr.end(), 0);
    int result = high;

    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (isPossible(arr, K, mid)) {
            result = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    // Step 3: Handle the result
    if (result < 100) {
        cout << fibonacci(result) << endl; // Find the Fibonacci number
    } else {
        cout << result << endl; // Return the result itself
    }

    return 0;
}