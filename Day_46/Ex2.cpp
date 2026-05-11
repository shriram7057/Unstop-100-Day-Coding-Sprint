#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

long long solve(const vector<int>& arr) {
    long long ans = 0;
    int mx = 0;

    for (int x : arr) {
        ans += x;
    }

    for (size_t i = 0; i < arr.size(); ++i) {
        ans += (arr.size() - i) * max(arr[i] - mx, 0);
        mx = max(mx, arr[i]);
    }

    return ans;
}

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
    cout << solve(arr) << endl;
    return 0;
}