#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Function prototype
int heightChecker(vector<int>& heights);

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    int result = heightChecker(arr);
    cout << result << endl;
    return 0;
}

// User needs to implement this function
int heightChecker(vector<int>& heights) {
    // User logic goes here
    vector<int> expected = heights;   // copy original
sort(expected.begin(), expected.end());

int count = 0;

for (int i = 0; i < heights.size(); i++) {
    if (heights[i] != expected[i]) {
        count++;
    }
}

return count;
}