#include <iostream>
#include <unordered_map>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int N;
    cin >> N;
    string s;
    cin >> s;
    
    unordered_map<char, int> pieces;
    int extra_needed = 0;
    
    for (char ch : s) {
        if (islower(ch)) {
            pieces[ch]++; // Collect the piece
        } else {
            char key = tolower(ch);
            if (pieces[key] > 0) {
                pieces[key]--; // Use an available piece
            } else {
                extra_needed++; // Buy an extra piece
            }
        }
    }
    
    cout << extra_needed << "\n";
    return 0;
}