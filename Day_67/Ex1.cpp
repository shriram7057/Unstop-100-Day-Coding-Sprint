#include <iostream>
#include <string>
#include <vector>
#include <limits>
using namespace std;

// Helper function to find the longest palindromic substring.
// In case of ties, we choose the one that appears last.
string longestPalindrome(const string &s) {
    int n = s.size();
    if(n == 0) return "";
    int start = 0, maxLen = 1;
    for (int i = 0; i < n; i++) {
        // Check for odd length palindromes.
        int l = i, r = i;
        while(l >= 0 && r < n && s[l] == s[r]) {
            int currLen = r - l + 1;
            if(currLen >= maxLen) { // update even if equal, to choose the later one
                start = l;
                maxLen = currLen;
            }
            l--; r++;
        }
        // Check for even length palindromes.
        l = i; r = i + 1;
        while(l >= 0 && r < n && s[l] == s[r]) {
            int currLen = r - l + 1;
            if(currLen >= maxLen) {
                start = l;
                maxLen = currLen;
            }
            l--; r++;
        }
    }
    return s.substr(start, maxLen);
}

// Helper function to find the smallest window in s that contains all characters of t 
// (with the same frequency).
string minWindow(const string &s, const string &t) {
    if(s.size() < t.size()) return "";
    vector<int> freqT(256, 0), freqS(256, 0);
    for (char c : t)
        freqT[c]++;
    
    int required = 0;
    for (int count : freqT)
        if(count > 0)
            required++;
    
    int l = 0, r = 0, formed = 0;
    int minLen = numeric_limits<int>::max(), minStart = 0;
    
    while(r < s.size()){
        char c = s[r];
        freqS[c]++;
        if(freqT[c] > 0 && freqS[c] == freqT[c])
            formed++;
        
        // Try and contract the window till the point it ceases to be 'desirable'.
        while(l <= r && formed == required){
            if(r - l + 1 < minLen){
                minLen = r - l + 1;
                minStart = l;
            }
            char lc = s[l];
            freqS[lc]--;
            if(freqT[lc] > 0 && freqS[lc] < freqT[lc])
                formed--;
            l++;
        }
        r++;
    }
    
    if(minLen == numeric_limits<int>::max())
        return "";
    return s.substr(minStart, minLen);
}

string user_logic(string str1, string str2, int k) {
    // Step 1: Find the longest palindromic substrings.
    string pal1 = longestPalindrome(str1);
    string pal2 = longestPalindrome(str2);
    
    // Step 2: Find the smallest substring in pal1 that contains all characters of pal2.
    string window = minWindow(pal1, pal2);
    
    // Step 3: Check if the length of this window is at least k.
    if(window != "" && window.size() >= k)
        return "YES";
    else
        return "NO";
}

int main() {
    std::string str1, str2;
    int k;
    std::cin >> str1 >> str2 >> k;
    std::cout << user_logic(str1, str2, k) << std::endl;
    return 0;
}