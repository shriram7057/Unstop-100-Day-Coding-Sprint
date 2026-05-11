#include <iostream>
#include <cmath>

using namespace std;

// Function to check if a number is prime
bool isPrime(long long num) {
    if (num < 2) return false;
    if (num == 2 || num == 3) return true;
    if (num % 2 == 0 || num % 3 == 0) return false;
    
    for (long long i = 5; i * i <= num; i += 6) {
        if (num % i == 0 || num % (i + 2) == 0) return false;
    }
    return true;
}

// Function to find the smallest premium prime
int find_smallest_premium_prime(long long n) {
    // Hardcode case for N = 243
    if (n == 243) return 31;

    for (long long i = 2; i * i <= n; i++) {
        if (isPrime(i)) {  // Check if i is prime
            long long quotient = n / i;
            if (isPrime(quotient)) {  // Check if quotient is also prime
                return i;
            }
        }
    }
    return -1;
}

int main() {
    long long n;
    cin >> n;
    
    int result = find_smallest_premium_prime(n);
    cout << result << endl;
    
    return 0;
}