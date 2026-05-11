#include <iostream>
#include <string>
#include <stack>
#include <vector>
using namespace std;

string reverseParentheses(string s) {
    int n = s.length();
    vector<int> pair(n);  // To store the matching parentheses pairs
    stack<int> openBrackets;

    // Step 1: Find pairs of parentheses
    for (int i = 0; i < n; ++i) {
        if (s[i] == '(') {
            openBrackets.push(i);
        } else if (s[i] == ')') {
            int j = openBrackets.top();
            openBrackets.pop();
            pair[i] = j;
            pair[j] = i;
        }
    }

    // Step 2: Build the result string
    string result;
    int i = 0;  // Starting index
    int d = 1;  // Direction (1 for forward, -1 for backward)

    while (i < n) {
        if (s[i] == '(' || s[i] == ')') {
            // Jump to the matching parenthesis and reverse direction
            i = pair[i];
            d = -d;
        } else {
            // Append the character to the result
            result += s[i];
        }
        i += d;  // Move in the current direction
    }

    return result;
}

int main() {
    string S;
    cin >> S;

    // Solve the problem and output the result
    cout << reverseParentheses(S) << endl;

    return 0;
}