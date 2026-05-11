#include<bits/stdc++.h>
using namespace std;

double findMiddleEarth(vector<int>& a1, vector<int>& a2) {
    int m = a1.size(), n = a2.size();
    
    if (m > n) return findMiddleEarth(a2, a1);

    int low = 0, high = m;
    int total = m + n;

    while (low <= high) {
        int cut1 = (low + high) / 2;
        int cut2 = (total + 1) / 2 - cut1;

        int l1 = (cut1 == 0) ? INT_MIN : a1[cut1 - 1];
        int l2 = (cut2 == 0) ? INT_MIN : a2[cut2 - 1];
        int r1 = (cut1 == m) ? INT_MAX : a1[cut1];
        int r2 = (cut2 == n) ? INT_MAX : a2[cut2];

        if (l1 <= r2 && l2 <= r1) {
            if (total % 2 == 0) {
                return (max(l1, l2) + min(r1, r2)) / 2.0;
            } else {
                return max(l1, l2);
            }
        } else if (l1 > r2) {
            high = cut1 - 1;
        } else {
            low = cut1 + 1;
        }
    }

    return 0.0;
}

int main() {
    int m, n;
    cin >> m >> n;
    vector<int> a1(m), a2(n);
    for(int i = 0; i < m; i++) {
        cin >> a1[i];
    }
    for(int i = 0; i < n; i++) {
        cin >> a2[i];
    }
    cout << fixed << setprecision(5) << findMiddleEarth(a1, a2) << endl;
    return 0;
}