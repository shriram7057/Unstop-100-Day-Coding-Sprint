#include <stdio.h>
#include <stdlib.h>

int min_cost(int v[], int n) {
    if (n <= 1) return 0;

    int dp[n];
    dp[0] = 0;

    for (int i = 1; i < n; i++) {
        int cost = abs(v[i] - v[i - 1]) + dp[i - 1];

        if (i - 2 >= 0) {
            int c2 = abs(v[i] - v[i - 2]) + dp[i - 2];
            if (c2 < cost) cost = c2;
        }

        if (i - 3 >= 0) {
            int c3 = abs(v[i] - v[i - 3]) + dp[i - 3];
            if (c3 < cost) cost = c3;
        }

        dp[i] = cost;
    }

    return dp[n - 1];
}

int main() {
    int n;
    scanf("%d", &n);

    int v[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &v[i]);
    }

    int result = min_cost(v, n);
    printf("%d\n", result);

    return 0;
}