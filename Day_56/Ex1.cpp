#include <iostream>
#include <string>
using namespace std;
void solve(string order, string s) {
    int freq[26] = {0};

    // Count frequency of characters in s
    for(char ch : s) {
        freq[ch - 'a']++;
    }

    string result = "";

    // Add characters according to custom order
    for(char ch : order) {
        while(freq[ch - 'a'] > 0) {
            result += ch;
            freq[ch - 'a']--;
        }
    }

    // Add remaining characters in alphabetical order
    for(int i = 0; i < 26; i++) {
        while(freq[i] > 0) {
            result += (char)(i + 'a');
            freq[i]--;
        }
    }

    cout << result;
}

int main() {
    string order, s;
    
    cin >> order >> s;
    
    solve(order, s);
    
    return 0;
}