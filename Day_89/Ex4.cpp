#include <bits/stdc++.h>
using namespace std;

// Function to flip the array up to index k
void flip(vector<int>& arr, int k) {
    reverse(arr.begin(), arr.begin() + k);
}

// Function to find the index of the maximum element up to index k
int findMaxIndex(vector<int>& arr, int k) {
    return max_element(arr.begin(), arr.begin() + k) - arr.begin();
}

vector<int> pancakeSort(vector<int>& arr) {
    vector<int> flips;
    int n = arr.size();
    
    for (int size = n; size > 1; size--) {
        int maxIdx = findMaxIndex(arr, size);
        
        // If the max element is not already at the end, move it
        if (maxIdx != size - 1) {
            // Step 1: Move the max element to the front if needed
            if (maxIdx != 0) {
                flips.push_back(maxIdx + 1);
                flip(arr, maxIdx + 1);
            }
            // Step 2: Move it to its correct position
            flips.push_back(size);
            flip(arr, size);
        }
    }
    
    return flips;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n;
    cin >> n;
    vector<int> arr(n);
    
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    vector<int> result = pancakeSort(arr);
    
    for (int k : result) {
        cout << k << " ";
    }
    cout << "\n";
    
    return 0;
}