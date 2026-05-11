#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void user_logic(int n, int k, int x, vector<int>& speeds) {
    sort(speeds.begin(), speeds.end());
    
    long long count = 0;
    int j = 0;

    for (int i = 0; i < n; i++) {
        while (j < n && speeds[j] - speeds[i] < k) {
            j++;
        }
        if (j < n) {
            count += (n - j);
        }
        if (count > x) {
            cout << "YES";
            return;
        }
    }

    cout << (count > x ? "YES" : "NO");
}

int main() {
    int n, k, x;
    cin >> n >> k >> x;
    vector<int> speeds(n);
    for (int i = 0; i < n; ++i) {
        cin >> speeds[i];
    }
    
    user_logic(n, k, x, speeds);
    return 0;
}