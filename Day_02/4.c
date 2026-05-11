#include <stdio.h>

int good_sum(int N, int A[]) {
    long long stack[100005];
    int top = -1;

    for (int i = 0; i < N; i++) {
        if (A[i] >= 0) {
            stack[++top] = A[i];
        } else {
            int need = -A[i];
            int removed_sum = 0;

            while (top >= 0 && removed_sum < need) {
                removed_sum += stack[top--];
            }

            stack[++top] = need;  // push absolute value
        }
    }

    long long total = 0;
    for (int i = 0; i <= top; i++) {
        total += stack[i];
    }

    return (int)total;
}

int main() {
    int N;
    scanf("%d", &N);

    int A[N];
    for (int i = 0; i < N; i++) {
        scanf("%d", &A[i]);
    }

    int result = good_sum(N, A);
    printf("%d\n", result);

    return 0;
}