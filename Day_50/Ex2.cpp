#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> A(N), answer(N), prefix(N, 1), suffix(N, 1);

    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }

    // Compute prefix products
    for (int i = 1; i < N; i++) {
        prefix[i] = prefix[i - 1] * A[i - 1];
    }

    // Compute suffix products
    for (int i = N - 2; i >= 0; i--) {
        suffix[i] = suffix[i + 1] * A[i + 1];
    }

    // Compute final answer
    for (int i = 0; i < N; i++) {
        answer[i] = prefix[i] * suffix[i];
        cout << answer[i] << endl;
    }

    return 0;
}