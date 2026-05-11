#include <iostream>
#include <vector>
using namespace std;

int max_water(const vector<int>& arr, int n) {
    int left = 0, right = n - 1;
    int leftMax = 0, rightMax = 0;
    int water = 0;

    while (left <= right) {
        if (arr[left] <= arr[right]) {
            if (arr[left] >= leftMax) {
                leftMax = arr[left];
            } else {
                water += leftMax - arr[left];
            }
            left++;
        } else {
            if (arr[right] >= rightMax) {
                rightMax = arr[right];
            } else {
                water += rightMax - arr[right];
            }
            right--;
        }
    }

    return water;
}

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
    cout << max_water(arr, n) << endl;
    return 0;
}