#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
#include <algorithm>

using namespace std;

// Check if string t is a subsequence of s.
bool is_subsequence(const string &s, const string &t) {
    int i = 0, j = 0;
    while (i < s.size() && j < t.size()) {
        if (s[i] == t[j]) {
            j++;
        }
        i++;
    }
    return j == t.size();
}

// Check if repeating sub k times forms a subsequence of s.
bool is_valid(const string &s, const string &sub, int k) {
    string repeated = "";
    for (int i = 0; i < k; i++) {
        repeated += sub;
    }
    return is_subsequence(s, repeated);
}

string best;   // global best valid subsequence found
int maxLen;    // maximum allowed length (s.size() / k)

void dfs(const string &s, int k, const vector<char> &candidates, const string &current) {
    // Update best: if current has a greater length,
    // or same length but lexicographically larger.
    if (current.size() > best.size() || 
       (current.size() == best.size() && current > best)) {
        best = current;
    }
    // Stop if we've reached the maximum possible length.
    if (current.size() == maxLen)
        return;
    
    // Try to append each candidate in descending order.
    for (size_t i = 0; i < candidates.size(); i++) {
        string new_seq = current + candidates[i];
        // Only continue if new_seq repeated k times is a subsequence of s.
        if (is_valid(s, new_seq, k)) {
            dfs(s, k, candidates, new_seq);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    string s;
    int k;
    getline(cin, s);
    cin >> k;
    
    // Maximum possible length for the subsequence.
    maxLen = s.size() / k;
    
    // Count frequency of each character.
    unordered_map<char, int> freq;
    for (size_t i = 0; i < s.size(); i++) {
        freq[s[i]]++;
    }
    
    // Only consider characters that appear at least k times.
    vector<char> candidates;
    for (unordered_map<char, int>::iterator it = freq.begin(); it != freq.end(); ++it) {
        if (it->second >= k)
            candidates.push_back(it->first);
    }
    
    // Sort candidates in descending order (lexicographically largest first).
    sort(candidates.begin(), candidates.end(), greater<char>());
    
    best = "";
    dfs(s, k, candidates, "");
    
    cout << best << "\n";
    
    return 0;
}