#include <bits/stdc++.h>
using namespace std;

int FirstWrongDecision(string s) {
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == 'W') {
            return i;
        }
    }
    return -1;
}

int main() {
    string str;
    cin >> str;
    // Call the function FirstWrongDecision().
    cout << FirstWrongDecision(str) << endl;
    return 0;
}