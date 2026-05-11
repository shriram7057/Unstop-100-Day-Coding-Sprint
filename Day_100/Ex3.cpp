#include<bits/stdc++.h>
using namespace std;

int countOnes(int num) {
    int ones = 0;
    while (num) {
        ones += (num & 1);
        num >>= 1;
    }
    return ones;
}

int main() {
    int limit;
    cin >> limit;

    vector<pair<int, int>> values;
    for (int i = 1; i <= limit; i++) {
        values.emplace_back(i, countOnes(i));
    }
    
    sort(values.begin(), values.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
        return a.second < b.second;
    });
    
    vector<int> sortedValues;
    for (const auto& val : values) {
        sortedValues.push_back(val.first);
    }
    
    int longestSeq = 0, currentSeq = 1;
    for (size_t i = 1; i < sortedValues.size(); i++) {
        if (sortedValues[i] > sortedValues[i - 1]) {
            currentSeq++;
        } else {
            longestSeq = max(longestSeq, currentSeq);
            currentSeq = 1;
        }
    }
    
    cout << max(longestSeq, currentSeq) << endl;
    return 0;
}