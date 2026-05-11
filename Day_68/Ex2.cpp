#include <iostream>
#include <string>
#include <unordered_map>
#include <climits>

using namespace std;

int shortestSubstring(string s, string t) {
    unordered_map<char, int> freq;
    for (char c : t) {
        freq[c]++;
    }
    int left = 0, right = 0, count = 0, len = INT_MAX;
    while (right < s.size()) {
        if (freq.find(s[right]) != freq.end()) {
            freq[s[right]]--;
            if (freq[s[right]] >= 0) {
                count++;
            }
            while (count == t.size()) {
                if (right - left + 1 < len) {
                    len = right - left + 1;
                }
                if (freq.find(s[left]) != freq.end()) {
                    freq[s[left]]++;
                    if (freq[s[left]] > 0) {
                        count--;
                    }
                }
                left++;
            }
        }
        right++;
    }
    return len == INT_MAX ? -1 : len;
}

int main() {
    string s, t;
    cin >> s >> t;
    cout << shortestSubstring(s, t) << endl;
    return 0;
}