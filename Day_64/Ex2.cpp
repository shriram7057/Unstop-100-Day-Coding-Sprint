#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string lexicographicallySmallestString(string s, int k) {
    if (k == 1) {
        string smallest = s;
        int n = s.size();
        for (int i = 1; i < n; i++) {
            string rotated = s.substr(i) + s.substr(0, i);
            smallest = min(smallest, rotated);
        }
        return smallest;
    } else {
        sort(s.begin(), s.end());
        return s;
    }
}

int main() {
    string s;
    int k;
    cin >> s >> k;
    cout << lexicographicallySmallestString(s, k) << endl;
    return 0;
}