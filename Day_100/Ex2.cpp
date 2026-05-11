#include <iostream>
#include <cmath>
using namespace std;

bool is_prime(int n) {
    if (n < 2) return false;
    for (int i = 2; i <= sqrt(n); ++i) {
        if (n % i == 0) return false;
    }
    return true;
}

int power_2(int n) {
    int count = 0;
    while (n != 0) {
        n >>= 1;
        count++;
    }
    return 1 << count;
}

int main() {
    int n;
    cin >> n;
    n = power_2(n);
    while (n > 0) {
        if (is_prime(n - 1)) {
            cout << n - 1 << endl;
            return 0;
        }
        n /= 2;
    }
    cout << -1 << endl;
    return 0;
}