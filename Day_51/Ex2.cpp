#include <iostream>
using namespace std;

// Function to compute the Josephus position
int josephus(int n, int k) {
    int survivor = 0; // Base case: for n=1, survivor is 0 (0-indexed)
    for (int i = 2; i <= n; i++) {
        survivor = (survivor + k) % i;
    }
    return survivor;
}

int main() {
    int T;
    cin >> T; // Number of test cases
    while (T--) {
        int N, K;
        cin >> N >> K;
        cout << josephus(N, K) << endl; // Output the result for each test case
    }
    return 0;
}