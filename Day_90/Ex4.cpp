#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int user_logic(int n, int x, vector<int>& arr) {
    unordered_map<int, int> freq;
    
    for (int i = 0; i < n; i++) {
        freq[arr[i]]++;
    }
    
    long long sum = 0;
    bool found = false;
    
    for (auto &p : freq) {
        if (p.second == x) {
            sum += p.first;
            found = true;
        }
    }
    
    if (!found) return -1;
    return sum;
}

int main() {
    int T;
    cin >> T;
    
    while (T--) {
        int N, X;
        cin >> N >> X;
        vector<int> arr(N);
        for (int i = 0; i < N; ++i) {
            cin >> arr[i];
        }
        
        int result = user_logic(N, X, arr);
        cout << result << endl;
    }
    
    return 0;
}