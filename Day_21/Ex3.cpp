#include <iostream>
#include <vector>
#include <tuple>
#include <unordered_map>
using namespace std;

vector<int> processQueries(vector<tuple<int, int, int>> queries) {
    vector<int> result;

    unordered_map<int, int> mp;

    for (auto q : queries) {
        int type = get<0>(q);
        int key = get<1>(q);
        int value = get<2>(q);

        if (type == 1) {
            // Insert or update
            mp[key] = value;
        }
        else if (type == 2) {
            // Get value
            if (mp.find(key) != mp.end())
                result.push_back(mp[key]);
            else
                result.push_back(-1);
        }
        else if (type == 3) {
            // Delete key
            mp.erase(key);
        }
    }

    return result;
}
int main() {
    int n;
    cin >> n;
    vector<tuple<int, int, int>> queries;
    for (int i = 0; i < n; ++i) {
        int queryType;
        cin >> queryType;
        if (queryType == 1) {
            int key, value;
            cin >> key >> value;
            queries.emplace_back(1, key, value);
        } else if (queryType == 2) {
            int key;
            cin >> key;
            queries.emplace_back(2, key, 0);
        } else if (queryType == 3) {
            int key;
            cin >> key;
            queries.emplace_back(3, key, 0);
        }
    }
    vector<int> results = processQueries(queries);
    for (int result : results) {
        cout << result << endl;
    }
    return 0;
}