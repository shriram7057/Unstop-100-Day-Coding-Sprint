#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

void change_longest(vector<int>& arr, int x) {

    int maxi = *max_element(arr.begin(), arr.end());

    for (int i = 0; i < arr.size(); i++) {

        if (arr[i] == maxi) {
            arr[i] = max(0, arr[i] - x);
        }
    }
}

bool pole_arrangement(const vector<int>& arr) {

    int n = arr.size();

    int leftMin = arr[0];

    multiset<int> right;

    // Insert all elements after index 1
    for (int i = 2; i < n; i++) {
        right.insert(arr[i]);
    }

    for (int j = 1; j < n - 1; j++) {

        // Find element strictly greater than leftMin
        auto it = right.upper_bound(leftMin);

        // Check if element is also smaller than arr[j]
        if (it != right.end() && *it < arr[j]) {
            return true;
        }

        leftMin = min(leftMin, arr[j]);

        // Remove next element as window shifts
        if (j + 1 < n) {
            auto eraseIt = right.find(arr[j + 1]);

            if (eraseIt != right.end()) {
                right.erase(eraseIt);
            }
        }
    }

    return false;
}

int main() {

    int n, x;
    cin >> n >> x;

    vector<int> arr(n);

    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    // Reduce tallest poles
    change_longest(arr, x);

    // Check arrangement
    bool result = pole_arrangement(arr);

    cout << (result ? 1 : 0) << endl;

    return 0;
}