#include <iostream>
#include <string>
using namespace std;

// Function to check if T is a subsequence of (D * S)
bool isSubsequence(const string &S, const string &T, int D) {
    int sLen = S.length(), tLen = T.length();
    int i = 0, j = 0;

    while (i < D * sLen && j < tLen) {
        if (S[i % sLen] == T[j])  // Match found, move T pointer
            j++;
        i++;  // Move in D*S
    }
    
    return j == tLen;  // If all T chars matched, return true
}

// Function to find the minimum day D
int findMinDays(string S, string T) {
    int left = 1, right = T.length(), ans = -1;

    while (left <= right) {
        int mid = (left + right) / 2;

        if (isSubsequence(S, T, mid)) {
            ans = mid;  // Found a valid D, try smaller
            right = mid - 1;
        } else {
            left = mid + 1;  // Need more repetitions
        }
    }

    return ans;
}

int main() {
    string S, T;
    cin >> S >> T;

    cout << findMinDays(S, T) << endl;
    return 0;
}