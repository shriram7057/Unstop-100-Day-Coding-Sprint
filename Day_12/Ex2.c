#include <stdio.h>

long long gcd(long long a, long long b) {
    while (b != 0) {
        long long temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

long long compute_x(long long p, long long n) {
    long long g = gcd(p, n);
    return (p / g) * n;  // safe multiplication to avoid overflow
}

int main() {
    long long p, n;
    scanf("%lld %lld", &p, &n);
    
    long long result = compute_x(p, n);
    printf("%lld\n", result);
    
    return 0;
}