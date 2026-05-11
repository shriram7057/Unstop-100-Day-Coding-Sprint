#include <iostream>
#include <vector>
using namespace std;

int count_workers_unable_to_collect_parts(const vector<int>& workers, const vector<int>& parts) {
    int count0 = 0, count1 = 0;

    // Count workers by type
    for (int w : workers) {
        if (w == 0) count0++;
        else count1++;
    }

    // Process parts in order
    for (int p : parts) {
        if (p == 0) {
            if (count0 > 0) count0--;
            else break;
        } else {
            if (count1 > 0) count1--;
            else break;
        }
    }

    return count0 + count1;
}

int main() {
    int n;
    cin >> n;

    vector<int> workers(n), parts(n);

    for (int i = 0; i < n; ++i) cin >> workers[i];
    for (int i = 0; i < n; ++i) cin >> parts[i];

    cout << count_workers_unable_to_collect_parts(workers, parts) << endl;

    return 0;
}