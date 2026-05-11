#include <stdio.h>

void user_logic(int n, int arr[], int *result) {
    if (n < 2) {
        *result = -1;
        return;
    }

    int min_val = arr[0];
    int max_diff = -1;

    for (int i = 1; i < n; i++) {
        if (arr[i] > min_val) {
            int diff = arr[i] - min_val;
            if (diff > max_diff) {
                max_diff = diff;
            }
        }
        if (arr[i] < min_val) {
            min_val = arr[i];
        }
    }

    *result = max_diff;
}

int main() {
    int T;
    scanf("%d", &T);
    int results[T];
    
    for (int t = 0; t < T; t++) {
        int N;
        scanf("%d", &N);
        int arr[N];
        for (int i = 0; i < N; i++) {
            scanf("%d", &arr[i]);
        }
        
        user_logic(N, arr, &results[t]);
    }
    
    for (int t = 0; t < T; t++) {
        printf("%d\n", results[t]);
    }
    
    return 0;
}