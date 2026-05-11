#include <iostream>
#include <string>
using namespace std;

int longestValidParentheses(string s) {
    int left = 0, right = 0, maxLength = 0;
    
    // Left to Right Pass
    for (char c : s) {
        if (c == '(') left++;
        else right++;

        if (left == right) {
            maxLength = max(maxLength, 2 * right);
        } else if (right > left) {
            left = right = 0;
        }
    }

    left = right = 0;
    
    // Right to Left Pass
    for (int i = s.length() - 1; i >= 0; i--) {
        if (s[i] == ')') right++;
        else left++;

        if (left == right) {
            maxLength = max(maxLength, 2 * left);
        } else if (left > right) {
            left = right = 0;
        }
    }

    return maxLength;
}

int main() {
    int n;
    string s;
    
    cin >> n;
    cin >> s;

    cout << longestValidParentheses(s) << endl;
    return 0;
}