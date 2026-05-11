#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

long long user_logic(int n, vector<int>& arr, vector<int>& b);

int main() {

    int n;
    cin >> n;

    vector<int> arr(n), b(n);

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }

    long long result = user_logic(n, arr, b);

    cout << result << endl;

    return 0;
}

long long user_logic(int n, vector<int>& arr, vector<int>& b) {

    sort(arr.begin(), arr.end());
    sort(b.begin(), b.end());

    long long interest1 = 0;
    long long interest2 = 0;

    for (int x : arr) {
        interest1 += upper_bound(b.begin(), b.end(), x) - b.begin();
    }

    for (int x : b) {
        interest2 += upper_bound(arr.begin(), arr.end(), x) - arr.begin();
    }

    return max(interest1, interest2);
}