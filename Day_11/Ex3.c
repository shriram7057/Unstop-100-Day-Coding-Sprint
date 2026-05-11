#include <stdio.h>

int count_good_indices(int n, int arr[]) {
    long long sum = 0;
    int count = 0;

    for (int i = 0; i < n; i++) {
        sum += arr[i];

        // Check if sum is power of 2
        if (sum > 0 && (sum & (sum - 1)) == 0) {
            count++;
        }
    }

    return count;
}

int main() {
    int n;
    scanf("%d", &n);
    
    int arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    
    int result = count_good_indices(n, arr);
    printf("%d\n", result);
    
    return 0;
}