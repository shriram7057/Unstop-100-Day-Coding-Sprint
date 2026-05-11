#include <iostream>
#define MOD 1000000007
using namespace std;

int countWaysToPaint(int N) {
    if (N == 1) return 12;

    long long A = 6, B = 6; // Base cases
    for (int i = 2; i <= N; i++) {
        long long newA = (2 * A + 2 * B) % MOD;
        long long newB = (2 * A + 3 * B) % MOD;
        A = newA;
        B = newB;
    }
    return (A + B) % MOD;
}

int main() {
    int N;
    cin >> N;
    cout << countWaysToPaint(N) << endl;
    return 0;
}