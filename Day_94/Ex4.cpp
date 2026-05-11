#include <iostream>
#include <vector>
using namespace std;

bool can_frog_cross_river(vector<int>& nums) {
    int maxReach = 0;

    for (int i = 0; i < nums.size(); i++) {
        if (i > maxReach) return false;
        maxReach = max(maxReach, i + nums[i]);
    }

    return true;
}
int main() {
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; ++i) {
        cin >> nums[i];
    }
    
    bool result = can_frog_cross_river(nums);
    cout << (result ? "true" : "false") << endl;
    return 0;
}