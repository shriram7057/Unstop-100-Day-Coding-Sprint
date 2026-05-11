#include <iostream>
#include <string>
#include <algorithm>
#include <climits>
using namespace std;

int main() {
    string currentState, desiredState, alterablePositions;
    cin >> currentState >> desiredState >> alterablePositions;
    
    // Check if lengths are equal
    if(currentState.length() != desiredState.length() || currentState.length() != alterablePositions.length()){
        cout << -1;
        return 0;
    }
    
    int n = currentState.length();
    
    // If the strings are empty, transformation is trivially 0 seconds.
    if(n == 0){
        cout << 0;
        return 0;
    }
    
    // Validate that currentState and desiredState contain only lowercase letters.
    for(char c : currentState) {
        if(c < 'a' || c > 'z') {
            cout << -1;
            return 0;
        }
    }
    for(char c : desiredState) {
        if(c < 'a' || c > 'z') {
            cout << -1;
            return 0;
        }
    }
    // Validate alterablePositions contains only '0' and '1'
    for(char c : alterablePositions) {
        if(c != '0' && c != '1') {
            cout << -1;
            return 0;
        }
    }
    
    int minTime = INT_MAX;
    // Try every possible rotation r, where r is the number of steps rotated clockwise.
    for (int r = 0; r < n; r++) {
        int rotationCost = 2 * min(r, n - r);
        int totalCost = rotationCost;
        bool valid = true;
        for (int i = 0; i < n; i++) {
            // Calculate the character at position i after rotation.
            char rotatedChar = currentState[(i - r + n) % n];
            if (rotatedChar != desiredState[i]) {
                if (alterablePositions[i] == '1') {
                    totalCost += 3; // Cost to change the character.
                } else {
                    valid = false;
                    break; // Cannot alter this character.
                }
            }
        }
        if(valid) {
            minTime = min(minTime, totalCost);
        }
    }
    
    cout << (minTime == INT_MAX ? -1 : minTime);
    return 0;
}