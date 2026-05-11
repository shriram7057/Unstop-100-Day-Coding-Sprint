#include <iostream>
#include <vector>
using namespace std;

void user_logic(int n, vector<int>& nums) {
    long long result = 0;

    for (int i = 0; i < n; i++) {
        if (i == 0 || nums[i] != nums[i - 1]) {
            result += (1LL << nums[i]);
        }
    }

    cout << result;
}

int main() {
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; ++i) {
        cin >> nums[i];
    }
    
    user_logic(n, nums);
    return 0;
}