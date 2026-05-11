#include <iostream>
#include <vector>
using namespace std;

int max_jamun(vector<int>& arr) {
    int n = arr.size();

    if (n == 0) return 0;
    if (n == 1) return arr[0];

    int prev2 = arr[0];
    int prev1 = max(arr[0], arr[1]);

    for (int i = 2; i < n; i++) {
        int curr = max(prev1, prev2 + arr[i]);
        prev2 = prev1;
        prev1 = curr;
    }

    return prev1;
}

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    int result = max_jamun(arr);
    cout << result << endl;
    return 0;
}