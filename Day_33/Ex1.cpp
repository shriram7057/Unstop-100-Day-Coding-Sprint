#include <iostream>
#include <vector>
using namespace std;

int findMajorityElement(vector<int>& nums, int N) {
    int candidate = 0, count = 0;
    
    // Boyer-Moore Voting Algorithm
    for (int num : nums) {
        if (count == 0) {
            candidate = num;
        }
        count += (num == candidate) ? 1 : -1;
    }
    
    return candidate;
}

int main() {
    int N;
    cin >> N;
    vector<int> nums(N);
    
    for (int i = 0; i < N; i++) {
        cin >> nums[i];
    }
    
    cout << findMajorityElement(nums, N) << endl;
    return 0;
}