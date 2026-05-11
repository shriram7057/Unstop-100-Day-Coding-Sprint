#include <iostream>
#include <vector>
#include <string>

using namespace std;
int MatchingCount(vector<vector<string>>& items, string ruleKey, string ruleValue) {
    int index = 0;

    if (ruleKey == "type") index = 0;
    else if (ruleKey == "color") index = 1;
    else index = 2; // "name"

    int count = 0;

    for (auto &item : items) {
        if (item[index] == ruleValue) {
            count++;
        }
    }

    return count;
}
int main() {
    int n;
    cin >> n;
    vector<vector<string>> items(n, vector<string>(3));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 3; j++) {
            cin >> items[i][j];
        }
    }

    string ruleKey, ruleValue;
    cin >> ruleKey >> ruleValue;

    // Call user logic function and print the output
    int result = MatchingCount(items, ruleKey, ruleValue);
    cout << result << endl;

    return 0;
}