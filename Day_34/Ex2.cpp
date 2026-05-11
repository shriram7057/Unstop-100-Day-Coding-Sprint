#include <bits/stdc++.h>
using namespace std;

int numSubarrayBoundedMax(vector<int>& A, int L, int R);

int main() {
    int n, l, r;
    cin >> n >> l >> r;
    vector<int> arr(n);
    for (auto &i : arr) cin >> i;
    cout << numSubarrayBoundedMax(arr, l, r) << endl;
    return 0;
}

int numSubarrayBoundedMax(vector<int>& A, int L, int R) {

    long long ans = 0;
    int lastInvalid = -1;
    int lastValid = -1;

    for (int i = 0; i < A.size(); i++) {

        if (A[i] > R) {
            lastInvalid = i;
        }

        if (A[i] >= L && A[i] <= R) {
            lastValid = i;
        }

        ans += max(0, lastValid - lastInvalid);
    }

    return ans;
}