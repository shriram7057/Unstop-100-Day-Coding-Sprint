#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;

bool wordBreak(string s, vector<string>& dictionary) {
    unordered_set<string> wordDict(dictionary.begin(), dictionary.end());
    int n = s.length();
    vector<bool> dp(n + 1, false);
    dp[0] = true;  // Empty string is always breakable
    
    // Check all substrings
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < i; j++) {
            if (dp[j] && wordDict.find(s.substr(j, i - j)) != wordDict.end()) {
                dp[i] = true;
                break;  // No need to check further
            }
        }
    }
    
    return dp[n];
}

int main() {
    string s;
    cin >> s;
    
    int n;
    cin >> n;
    vector<string> dictionary(n);
    for (int i = 0; i < n; i++) {
        cin >> dictionary[i];
    }
    
    cout << (wordBreak(s, dictionary) ? "true" : "false") << endl;
    
    return 0;
}