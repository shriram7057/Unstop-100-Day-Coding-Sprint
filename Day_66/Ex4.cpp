#include <bits/stdc++.h>
using namespace std;

int countZeroANDSubarrays(vector<int>& nums) {
    int used = 0, j = 0, res = 0;
    int k = -1;
    
    for (int i = 0; i < nums.size(); ++i) {
        k++;
        while ((used & nums[i]) != 0) {
            used ^= nums[j++];
            k--;
        }
        used |= nums[i];
        res += max(0, k);
    }
    
    return res;
}

int main() {
    int n;
    // Taking input
    cin >> n;
    vector<int> v(n);
    
    for (int &i : v) {
        cin >> i;
    }
    
    cout << countZeroANDSubarrays(v) << endl;
    return 0;
}