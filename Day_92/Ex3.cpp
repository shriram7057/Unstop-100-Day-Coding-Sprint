#include <iostream>
#include <vector>
using namespace std;

int get_xor_sum(const vector<int>& arr1, const vector<int>& arr2) {
    int x1 = 0, x2 = 0;

    for (int x : arr1) x1 ^= x;
    for (int x : arr2) x2 ^= x;

    return x1 & x2;
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> arr1(n), arr2(m);
    for (int i = 0; i < n; ++i) cin >> arr1[i];
    for (int i = 0; i < m; ++i) cin >> arr2[i];

    cout << get_xor_sum(arr1, arr2) << endl;
    return 0;
}