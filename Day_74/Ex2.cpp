#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

/*
Merge intervals that overlap or touch.
Then, for each merged interval, compute (end - start) and return the minimum.
*/
int user_logic(vector<vector<int>>& intervals) {
    // Sort intervals based on starting time.
    sort(intervals.begin(), intervals.end(), [](const vector<int>& a, const vector<int>& b) {
        return a[0] < b[0];
    });
    
    // Merge overlapping intervals (touching intervals count as overlapping).
    vector<pair<int,int>> merged;
    for (auto &intv : intervals) {
        if (merged.empty() || intv[0] > merged.back().second) {
            merged.push_back({intv[0], intv[1]});
        } else {
            merged.back().second = max(merged.back().second, intv[1]);
        }
    }
    
    // Calculate the difference (end - start) for each merged interval and find the minimum.
    int minDiff = INT_MAX;
    for (auto &m : merged) {
        int diff = m.second - m.first;
        minDiff = min(minDiff, diff);
    }
    return minDiff;
}

int main() {
    int n;
    cin >> n;
    vector<vector<int>> intervals(n, vector<int>(2));
    for (int i = 0; i < n; i++) {
        cin >> intervals[i][0] >> intervals[i][1];
    }
    
    int result = user_logic(intervals);
    cout << result << endl;
    return 0;
}