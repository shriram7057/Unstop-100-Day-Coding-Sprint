#include <bits/stdc++.h>
using namespace std;

// Function to find the K-th next permutation
vector<string> kthNextPermutation(vector<string> items, long long k) {
    long long n = items.size();

    // Total number of permutations
    long long totalPermutations = 1;
    for (long long i = 2; i <= n; ++i) totalPermutations *= i;

    // Optimize K for cases where K > totalPermutations
    k = k % totalPermutations;

    // Generate permutations
    while (k--) {
        next_permutation(items.begin(), items.end());
    }

    return items;
}

int main() {
    long long n, k;
    cin >> n;
    vector<string> items(n);

    // Input food items
    for (long long i = 0; i < n; ++i) {
        cin >> items[i];
    }

    cin >> k;

    // Get the K-th next permutation
    vector<string> result = kthNextPermutation(items, k);

    // Output the result
    for (const string& item : result) {
        cout << item << " ";
    }
    cout << endl;

    return 0;
}