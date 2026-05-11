#include <iostream>
#include <vector>

using namespace std;

void swap(int &a,int &b){
    int t = a;
    a = b;
    b = t;
}

int quickselect (int l, int r, vector<int>& nums, int k){
    
    int piviot = nums[r], p = l;
    for(int i=l;i<r;i++){
        if(nums[i] <= piviot){
            swap(nums[i],nums[p]);
            p++;
        }
    }
    swap(nums[p], nums[r]);
    if(p > k){
       return quickselect(l,p-1,nums,k);
    }
    else if(p < k){
        return quickselect(p+1,r,nums,k);
    }
    else
    return nums[p];
}

int find_kth_largest(std::vector<int>& nums, int k) {
    // Write your logic here.
    k = nums.size() - k;
    int ans = quickselect(0,nums.size()-1, nums,k);
    return ans;
}

int main() {
    int n, k;
    std::cin >> n >> k;
    std::vector<int> nums(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> nums[i];
    }
    int result = find_kth_largest(nums, k);
    std::cout << result << std::endl;
    return 0;
}