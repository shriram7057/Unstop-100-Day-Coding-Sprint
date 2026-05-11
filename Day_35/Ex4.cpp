#include <iostream>
#include <vector>
using namespace std;
int find_minimum_k(int a, int b, int c) {
    long long target = 1LL * 4 * a * c;

    for (int k = 0; ; k++) {
        long long d1 = 1LL * (b - k) * (b - k);
        long long d2 = 1LL * (b + k) * (b + k);

        if (d1 >= target || d2 >= target) {
            return k;
        }
    }
}

int main() {
    int T;
    cin >> T;
    vector<int> results(T);
    for (int i = 0; i < T; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        results[i] = find_minimum_k(a, b, c);
    }
    for (int i = 0; i < T; i++) {
        cout << results[i] << endl;
    }
    return 0;
}