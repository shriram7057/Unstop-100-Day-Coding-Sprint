#include <iostream>
#include <string>
#include <vector>
using namespace std;

string user_logic(int n, const string& s) {
    vector<int> freq(26, 0);
    
    for (char c : s) {
        freq[c - 'a']++;
    }
    
    int oddCount = 0;
    for (int i = 0; i < 26; i++) {
        if (freq[i] % 2 != 0) oddCount++;
    }
    
    if (oddCount <= 1) {
        return "-1";
    }
    
    // Minimum characters needed = oddCount - 1
    string result = "";
    int needed = oddCount - 1;
    
    for (int i = 0; i < 26 && needed > 0; i++) {
        if (freq[i] % 2 != 0) {
            result += char(i + 'a');
            needed--;
        }
    }
    
    return result;
}

int main() {
    int n;
    string s;
    
    cin >> n;
    cin >> s;
    
    cout << user_logic(n, s) << endl;
    return 0;
}