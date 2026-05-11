#include <iostream>
using namespace std;

// Function to solve the problem
int solve(long long A, long long B, long long C, long long D) {
    long long d = D;
    long long b = B;
    long long a = A;
    long long c = C;
    long long q = d * b;

    if (q >= a) {
        return -1;
    }

    for (long long i = b; i >= 0; --i) {
        long long ele = i * (c - d) + q;
        if (ele < a) {
            return i;
        }
    }
    return -1;
}

int main() {
    // Input
    long long A, B, C, D;
    cin >> A >> B >> C >> D;

    // Output the result
    cout << solve(A, B, C, D) << endl;

    return 0;
}