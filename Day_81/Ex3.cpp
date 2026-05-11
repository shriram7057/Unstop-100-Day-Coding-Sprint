#include <bits/stdc++.h>
using namespace std;

vector<int> user_logic(int n, vector<int>& arr, int q, vector<int>& queries) {
    vector<int> ans;

    // Sort the array for binary search
    sort(arr.begin(), arr.end());

    for (int x : queries) {
        // Find first element >= x
        auto it = lower_bound(arr.begin(), arr.end(), x);

        if (it == arr.end()) {
            ans.push_back(-1);
        } else {
            ans.push_back(*it);
        }
    }

    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    vector<int> results;
    
    for (int i = 0; i < t; ++i) {
        int n;
        cin >> n;

        vector<int> arr(n);
        for (int j = 0; j < n; ++j) {
            cin >> arr[j];
        }

        int q;
        cin >> q;

        vector<int> queries(q);
        for (int k = 0; k < q; ++k) {
            cin >> queries[k];
        }

        // Call user logic function
        vector<int> result = user_logic(n, arr, q, queries);

        results.insert(results.end(), result.begin(), result.end());
    }

    // Print all results
    for (const int& res : results) {
        cout << res << '\n';
    }

    return 0;
}