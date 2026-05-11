#include <stdio.h>

int calculate_f_score(int features[], int N) {
    int result = 0;

    for (int i = 0; i < N; i++) {
        long long count = (long long)(i + 1) * (N - i);
        if (count % 2 != 0) {
            result ^= features[i];
        }
    }

    return result;
}

int main() {
    int N;
    scanf("%d", &N);

    int features[N];
    for (int i = 0; i < N; i++) {
        scanf("%d", &features[i]);
    }
    
    int result = calculate_f_score(features, N);
    printf("%d\n", result);
    return 0;
}