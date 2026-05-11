#include <stdio.h>
#include <string.h>

int isPrime(int x) {
    if (x < 2) return 0;
    for (int i = 2; i * i <= x; i++) {
        if (x % i == 0) return 0;
    }
    return 1;
}

void modify_string(int n, char* s) {
    int sum = 0, count = 0;

    // find primes among digits
    for (int i = 0; i < n; i++) {
        if (s[i] >= '0' && s[i] <= '9') {
            int val = s[i] - '0';
            if (isPrime(val)) {
                sum += val;
                count++;
            }
        }
    }

    int unique = 0;
    if (count > 0) unique = sum / count;

    // modify string
    for (int i = 0; i < n; i++) {
        if (s[i] >= '0' && s[i] <= '9') {
            int val = s[i] - '0';
            int idx;

            if (count > 0) {
                idx = val % unique;
            } else {
                idx = val;
            }

            s[i] = 'a' + idx;
        }
    }

    printf("%s\n", s);
}

int main() {
    int n;
    char s[10001];
    scanf("%d %s", &n, s);
    modify_string(n, s);
    return 0;
}