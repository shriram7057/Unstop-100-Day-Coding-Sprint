#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int MOD = 1000007; // 10^6 + 7

// Extended Euclidean Algorithm to find x and y such that: a*x + b*y = gcd(a, b)
int extended_gcd(int a, int b, int &x, int &y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    int x1, y1;
    int g = extended_gcd(b, a % b, x1, y1);
    x = y1;
    y = x1 - (a / b) * y1;
    return g;
}

// Function to compute the modular multiplicative inverse of a modulo mod
int modInverse(int a, int mod) {
    int x, y;
    int g = extended_gcd(a, mod, x, y);
    // Inverse exists if and only if a and mod are coprime (i.e., gcd(a, mod) == 1)
    if (g != 1) {
        return -1; // No modular inverse exists
    }
    // Ensure x is positive
    return (x % mod + mod) % mod;
}

// Function to compute the length of the longest increasing subsequence (LIS)
// and then return its modular multiplicative inverse modulo MOD.
int calculateInverseOfLISLength(int n, vector<int>& heights) {
    vector<int> lis;
    // O(n log n) approach to compute the length of the LIS
    for (int height : heights) {
        auto it = lower_bound(lis.begin(), lis.end(), height);
        if (it == lis.end()) {
            lis.push_back(height);
        } else {
            *it = height;
        }
    }
    int lisLength = lis.size();
    return modInverse(lisLength, MOD);
}

int main() {
    int n;
    cin >> n;
    vector<int> heights(n);
    for (int i = 0; i < n; i++) {
        cin >> heights[i];
    }

    int result = calculateInverseOfLISLength(n, heights);
    cout << result << endl;

    return 0;
}