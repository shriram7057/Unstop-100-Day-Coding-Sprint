#include <iostream>
using namespace std;

long long comb(int n, int r) {
    if (r > n) return 0;
    if (r > n - r) r = n - r;
    
    long long res = 1;
    for (int i = 0; i < r; i++) {
        res = res * (n - i) / (i + 1);
    }
    return res;
}

long long user_logic(int x, int y) {
    if (x % 2 != 0 || y % 2 != 0) return 0;
    
    int a = x / 2;
    int b = y / 2;
    
    return comb(a + b, a);
}

int main() {
    int x, y;
    cin >> x >> y;
    cout << user_logic(x, y) << endl;
    return 0;
}