#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Function to compute the maximum sum after partitioning
int maxSumAfterPartitioning(vector<int>& arr, int N, int K) {
    vector<int> dp(N + 1, 0);
    
    for (int i = 1; i <= N; ++i) {
        int maxVal = 0, best = 0;
        for (int j = 1; j <= K && i - j >= 0; ++j) {
            maxVal = max(maxVal, arr[i - j]);
            best = max(best, dp[i - j] + maxVal * j);
        }
        dp[i] = best;
    }
    return dp[N];
}

// Function to count prime numbers up to a given limit using Sieve of Eratosthenes
int countPrimes(int M) {
    if (M < 2) return 0;
    vector<bool> isPrime(M + 1, true);
    isPrime[0] = isPrime[1] = false;
    
    for (int i = 2; i * i <= M; ++i) {
        if (isPrime[i]) {
            for (int j = i * i; j <= M; j += i) {
                isPrime[j] = false;
            }
        }
    }
    return count(isPrime.begin(), isPrime.end(), true);
}

int main() {
    int N, K;
    cin >> N;
    vector<int> arr(N);
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }
    cin >> K;
    
    int M = maxSumAfterPartitioning(arr, N, K);
    int primeCount = countPrimes(M);
    
    cout << primeCount << endl;
    return 0;
}