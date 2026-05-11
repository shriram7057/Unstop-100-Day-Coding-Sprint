#include <iostream>
#include <vector>
using namespace std;

int longestSmallBigPattern(vector<int>& arr) {
    int n = arr.size();
    if (n == 1) return 1;

    int up = 1, down = 1; // Lengths of longest sequences
    int maxLength = 1;

    for (int i = 1; i < n; i++) {
        if (arr[i] > arr[i-1]) {
            up = down + 1;
        } else if (arr[i] < arr[i-1]) {
            down = up + 1;
        }
        maxLength = max(maxLength, max(up, down));
    }
    return maxLength;
}

int main() {
    int N;
    cin >> N;
    vector<int> arr(N);
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }
    cout << longestSmallBigPattern(arr) << endl;
    return 0;
}