#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <unordered_map>
using namespace std;

int main() {
    int n;
    cin >> n;
    
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    int target;
    cin >> target;
    
    unordered_map<int, int> freq;
    long long count = 0;
    
    for (int i = 0; i < n; i++) {
        int needed = target - arr[i];
        if (freq.count(needed)) {
            count += freq[needed];
        }
        freq[arr[i]]++;
    }
    
    cout << count;
    return 0;
}