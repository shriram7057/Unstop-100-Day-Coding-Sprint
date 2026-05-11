#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>
using namespace std;

// Function to find the minimum in each sliding window of size `w`
vector<int> getMinInWindow(vector<int>& arr, int w) {
    int n = arr.size();
    vector<int> minValues;
    deque<int> dq;  // Deque to store indexes of elements
    
    for (int i = 0; i < n; i++) {
        // Remove elements out of window
        while (!dq.empty() && dq.front() < i - w + 1) {
            dq.pop_front();
        }

        // Remove elements greater than current element (maintaining increasing order)
        while (!dq.empty() && arr[dq.back()] > arr[i]) {
            dq.pop_back();
        }

        dq.push_back(i);

        // Store min value for this window
        if (i >= w - 1) {
            minValues.push_back(arr[dq.front()]);
        }
    }
    
    return minValues;
}

int main() {
    int n;
    cin >> n;

    vector<int> arr, luckyArray;

    // Step 1: Read and filter out negative numbers
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        if (x >= 0) arr.push_back(x);
    }

    // Step 2 & 3: Process windows of size 1 to arr.size()
    int newSize = arr.size();
    for (int w = 1; w <= newSize; w++) {
        vector<int> minVals = getMinInWindow(arr, w);
        int maxOfMin = *max_element(minVals.begin(), minVals.end());
        luckyArray.push_back(maxOfMin);
    }

    // Step 4: Print Lucky Array
    for (int num : luckyArray) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}