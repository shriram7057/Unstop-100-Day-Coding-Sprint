#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

// Function to check if all strings in arr can be formed using characters from S
bool canFormStrings(const string& s, const vector<string>& arr) {
    // Step 1: Build frequency map of characters in S
    unordered_map<char, int> s_freq;
    for (char c : s) {
        s_freq[c]++;
    }

    // Step 2: Check if each string in arr can be formed using characters from S
    for (const string& word : arr) {
        unordered_map<char, int> word_freq;
        for (char c : word) {
            word_freq[c]++;
            // If character c is not in S or exceeds available count, return false
            if (word_freq[c] > s_freq[c]) {
                return false;
            }
        }
    }
    
    return true; // All words can be formed
}

int main() {
    string s;
    getline(cin, s);  // Read the input string S

    int n;
    cin >> n;  // Read the number of strings in the array
    cin.ignore();  // Ignore newline after integer input

    vector<string> arr(n);
    for (int i = 0; i < n; ++i) {
        getline(cin, arr[i]);  // Read each string
    }

    // Call function and output result
    cout << (canFormStrings(s, arr) ? "true" : "false") << endl;

    return 0;
}