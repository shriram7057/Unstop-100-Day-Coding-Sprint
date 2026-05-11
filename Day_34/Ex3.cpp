#include <iostream>
#include <vector>

void smallerNumbersThanCurrent(const std::vector<int>& nums, std::vector<int>& result) {

    std::vector<int> freq(101, 0);

    for (int num : nums) {
        freq[num]++;
    }

    for (int i = 1; i <= 100; i++) {
        freq[i] += freq[i - 1];
    }

    for (int i = 0; i < nums.size(); i++) {
        if (nums[i] == 0)
            result[i] = 0;
        else
            result[i] = freq[nums[i] - 1];
    }
}
int main() {
    int n;
    std::cin >> n;
    std::vector<int> nums(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> nums[i];
    }
    
    std::vector<int> result(n);
    smallerNumbersThanCurrent(nums, result);
    
    for (int i = 0; i < n; ++i) {
        std::cout << result[i] << " ";
    }
    std::cout << std::endl;
    
    return 0;
}