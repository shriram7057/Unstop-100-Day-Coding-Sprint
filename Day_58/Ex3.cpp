#include <iostream>
#include <vector>
void user_logic(int n, std::vector<int>& arr) {
    std::vector<int> temp;
    
    int left = 0;
    int right = n - 1;

    // Arrange as max, min, 2nd max, 2nd min...
    while (left <= right) {
        if (left != right) {
            temp.push_back(arr[right--]);
            temp.push_back(arr[left++]);
        } else {
            temp.push_back(arr[left++]);
        }
    }

    // Rotate left by n/2 steps
    int s = n / 2;

    std::vector<int> rotated;

    for (int i = s; i < n; i++) {
        rotated.push_back(temp[i]);
    }

    for (int i = 0; i < s; i++) {
        rotated.push_back(temp[i]);
    }

    arr = rotated;
}

int main() {
    int n;
    std::cin >> n;
    std::vector<int> arr(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> arr[i];
    }
    user_logic(n, arr);
    for (const int& num : arr) {
        std::cout << num << " ";
    }
    return 0;
}