#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Placeholder function for user logic
string firstPalindrome(const vector<string>& words) {
    // User should implement the logic here
    // This function should return the first palindromic string in the array
    // If no such string exists, return an empty string ""
    for (const string& word : words) {
    bool isPalindrome = true;
    int left = 0, right = word.length() - 1;

    while (left < right) {
        if (word[left] != word[right]) {
            isPalindrome = false;
            break;
        }
        left++;
        right--;
    }

    if (isPalindrome) {
        return word;
    }
}
    return "";
}

int main() {
    int n;
    cin >> n; // Read the number of strings
    
    if (n <= 0) { // Edge case: No strings provided
        cout << "" << endl;
        return 0;
    }
    
    vector<string> arr(n);
    for (int i = 0; i < n; ++i) {
        cin >> arr[i]; // Read each string into the array
    }
    
    // Call user logic function and print the output
    string result = firstPalindrome(arr);
    cout << result << endl;
    
    return 0;
}
