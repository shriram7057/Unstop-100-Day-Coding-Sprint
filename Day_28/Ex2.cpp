#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {

    int n, m;
    cin >> n >> m;

    vector<int> a(n), b(m);

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    for (int i = 0; i < m; i++) {
        cin >> b[i];
    }

    int i = n - 1;
    int j = m - 1;

    int answer = -1;

    // Find common suffix
    while (i >= 0 && j >= 0 && a[i] == b[j]) {
        answer = a[i];
        i--;
        j--;
    }

    cout << answer;

    return 0;
}