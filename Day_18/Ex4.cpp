#include <iostream>
#include <vector>

using namespace std;

bool user_logic(int n, vector<int>& runs) {
    int maxReach = 0;

    for (int i = 0; i < n; i++) {
        if (i > maxReach) return false;

        maxReach = max(maxReach, i + runs[i]);

        if (maxReach >= n - 1) return true;
    }

    return false;
}

int main() {
    int n;
    cin >> n;

    vector<int> runs(n);
    for (int i = 0; i < n; ++i) {
        cin >> runs[i];
    }

    // Call user logic function and print the output
    bool result = user_logic(n, runs);
    cout << (result ? "true" : "false") << endl;

    return 0;
}
#include <iostream>
#include <vector>

using namespace std;

bool user_logic(int n, vector<int>& runs) {
    int maxReach = 0;

    for (int i = 0; i < n; i++) {
        if (i > maxReach) return false;

        maxReach = max(maxReach, i + runs[i]);

        if (maxReach >= n - 1) return true;
    }

    return false;
}

int main() {
    int n;
    cin >> n;

    vector<int> runs(n);
    for (int i = 0; i < n; ++i) {
        cin >> runs[i];
    }

    // Call user logic function and print the output
    bool result = user_logic(n, runs);
    cout << (result ? "true" : "false") << endl;

    return 0;
}
