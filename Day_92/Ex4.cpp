#include <iostream>
#include <vector>
using namespace std;

int user_logic(int n, int m, vector<vector<int>>& grid) {
    // Step 1: maximize matrix score
    // Make first column all 1s
    for (int i = 0; i < n; i++) {
        if (grid[i][0] == 0) {
            for (int j = 0; j < m; j++) {
                grid[i][j] ^= 1;
            }
        }
    }

    // For each column, maximize number of 1s
    for (int j = 1; j < m; j++) {
        int ones = 0;
        for (int i = 0; i < n; i++) {
            if (grid[i][j] == 1) ones++;
        }
        if (ones < n - ones) {
            for (int i = 0; i < n; i++) {
                grid[i][j] ^= 1;
            }
        }
    }

    // Step 2: compute score
    int score = 0;
    for (int i = 0; i < n; i++) {
        int val = 0;
        for (int j = 0; j < m; j++) {
            val = val * 2 + grid[i][j];
        }
        score += val;
    }

    // Step 3: count primes <= score using sieve
    if (score < 2) return 0;

    vector<bool> isPrime(score + 1, true);
    isPrime[0] = isPrime[1] = false;

    for (int i = 2; i * i <= score; i++) {
        if (isPrime[i]) {
            for (int j = i * i; j <= score; j += i) {
                isPrime[j] = false;
            }
        }
    }

    int count = 0;
    for (int i = 2; i <= score; i++) {
        if (isPrime[i]) count++;
    }

    return count;
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> elements(n * m);
    for (int i = 0; i < n * m; ++i) {
        cin >> elements[i];
    }

    vector<vector<int>> grid(n, vector<int>(m));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            grid[i][j] = elements[i * m + j];
        }
    }

    cout << user_logic(n, m, grid) << endl;
    return 0;
}