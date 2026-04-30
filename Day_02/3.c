#include <stdio.h>

// User logic function
int highestAltitude(int n, int arr[]) {
    int current = 0;
    int max_alt = 0;

    for (int i = 0; i < n; i++) {
        current += arr[i];
        if (current > max_alt) {
            max_alt = current;
        }
    }

    return max_alt;
}

int main() {
    int n;
    scanf("%d", &n);

    int arr[n];
    for (int i = 0; i < n; ++i) {
        scanf("%d", &arr[i]);
    }

    int result = highestAltitude(n, arr);
    printf("%d\n", result);

    return 0;
}