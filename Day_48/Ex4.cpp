#include <iostream>
#include <string>
#include <utility>
using namespace std;

string longestPalindrome(string s) {
    if (s.empty()) return "";
    int start = 0, end = 0;
    
    // Helper function to expand from the center and return the boundaries of the palindrome.
    auto expandAroundCenter = [&](int left, int right) -> pair<int,int> {
        while (left >= 0 && right < s.size() && s[left] == s[right]) {
            left--;
            right++;
        }
        return make_pair(left + 1, right - 1);
    };
    
    for (int i = 0; i < s.size(); i++) {
        // Check for odd-length palindrome
        pair<int,int> p1 = expandAroundCenter(i, i);
        if (p1.second - p1.first >= end - start) {  // use '>=' to update if equal length
            start = p1.first;
            end = p1.second;
        }
        
        // Check for even-length palindrome
        pair<int,int> p2 = expandAroundCenter(i, i + 1);
        if (p2.second - p2.first >= end - start) {  // use '>=' to update if equal length
            start = p2.first;
            end = p2.second;
        }
    }
    
    return s.substr(start, end - start + 1);
}

int main() {
    string s;
    getline(cin, s); // Read input string
    cout << longestPalindrome(s) << endl;
    return 0;
}