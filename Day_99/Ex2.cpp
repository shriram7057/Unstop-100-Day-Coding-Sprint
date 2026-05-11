#include <iostream>
#include <vector>
using namespace std;

int numTimesAllBlue(vector<int>& flips) {
    int maxFlipped = 0;
    int count = 0;

    for (int i = 0; i < flips.size(); ++i) {
        maxFlipped = max(maxFlipped, flips[i]);
        if (maxFlipped == i + 1) {
            count++;
        }
    }

    return count;
}

int main() {
    int n;
    cin >> n;
    vector<int> flips(n);

    for (int i = 0; i < n; ++i) {
        cin >> flips[i];
    }

    int result = numTimesAllBlue(flips);
    cout << result << endl;

    return 0;
}