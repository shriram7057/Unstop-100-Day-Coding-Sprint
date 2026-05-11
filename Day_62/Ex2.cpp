#include <iostream>
#include <string>
#include <climits>
using namespace std;

// Function to calculate the longest "good" substring
int get_ans(const string& s) {
    int ans = INT_MIN; // Initialize to smallest possible value
    int maxi = 1;

    for (size_t i = 1; i < s.length(); ++i) {
        if (s[i - 1] + 1 == s[i]) {
            maxi += 1;
        } else {
            ans = max(ans, maxi);
            maxi = 1;
        }
    }
    return max(ans, maxi);
}

// Function to solve the problem
int solve(string str) {
    if (str.length() == 1) {
        return 1;
    }
    size_t n = str.length();
    if (str[n - 2] != 'z') {
        str[n - 1] = str[n - 2] + 1;
    }
    return get_ans(str);
}

int main() {
    string str;
    cin >> str; // Input the string
    cout << solve(str) << endl; // Output the result
    return 0;
}