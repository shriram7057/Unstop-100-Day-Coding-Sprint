#include <iostream>
#include <vector>
#include <string>
#include<map>
#include <unordered_set>
using namespace std;

bool generateCount(vector<string> list, string s);

int main() {
    string s;
    getline(cin, s);
    
    int n;
    cin >> n;
    cin.ignore();

    vector<string> list(n);
    for (int i = 0; i < n; ++i) {
        cin>>list[i];
    }
    
    cout << (generateCount(list, s) ? "true" : "false") << endl;
    
    return 0;
}

bool generateCount(vector<string> list, string s) {
     map<char, int> ans;
    for (char ch : s) {
        ans[ch]++;
    }

    for (const string& st : list) {
        map<char, int> mp; 
        for (char ch : st) {
            mp[ch]++;
            if (mp[ch] > ans[ch]) {
                return false;
            }
        }
    }

    return true;
}