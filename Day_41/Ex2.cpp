  #include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

// Function to check if a given K can clear all enemies in M minutes
bool canKillAll(const vector<int>& groups, int K, int M) {
    long long totalMinutes = 0;
    
    for (int enemies : groups) {
        totalMinutes += ceil((double)enemies / K);
        if (totalMinutes > M) return false;
    }
    
    return totalMinutes <= M;
}

// Function to find the minimum K using binary search
int findMinimumK(const vector<int>& groups, int M) {
    int left = 1, right = *max_element(groups.begin(), groups.end()), result = -1;
    
    while (left <= right) {
        int mid = left + (right - left) / 2;
        
        if (canKillAll(groups, mid, M)) {
            result = mid;  // Store potential answer
            right = mid - 1;  // Try to find a smaller K
        } else {
            left = mid + 1;
        }
    }
    
    return result == -1 ? 1 : result;
}

int main() {
    int N, M;
    
    // Read input values
    cin >> N;
    vector<int> groups(N);
    
    for (int i = 0; i < N; i++) {
        cin >> groups[i];
    }
    
    cin >> M;
    
    // Find the minimum K
    int minK = findMinimumK(groups, M);
    
    // Convert minK to octal
    cout << minK << " " << oct << minK << endl;
    
    return 0;
}