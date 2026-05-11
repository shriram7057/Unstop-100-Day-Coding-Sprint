#include <bits/stdc++.h>
using namespace std;

int countUniqueIncreasingSubstrings(string S) {
    unordered_set<string> uniqueSubstrings;
    int n = S.length();

    for (int i = 0; i < n; i++) {
        string temp = "";
        temp += S[i]; // Single character substring
        uniqueSubstrings.insert(temp);

        for (int j = i + 1; j < n; j++) {
            if (S[j] > S[j - 1]) { // Increasing condition
                temp += S[j];
                uniqueSubstrings.insert(temp);
            } else {
                break;
            }
        }
    }

    return uniqueSubstrings.size();
}

int main() {
    int N;
    string S;
    cin >> N >> S;
    cout << countUniqueIncreasingSubstrings(S) << endl;
    return 0;
}