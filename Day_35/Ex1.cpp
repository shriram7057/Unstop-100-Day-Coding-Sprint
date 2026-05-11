#include <iostream>
using namespace std;
char find_digit_at_position(int N) {
    long long digits = 1;
    long long count = 9;
    long long start = 1;

    // Find the range where N lies
    while (N > digits * count) {
        N -= digits * count;
        digits++;
        count *= 10;
        start *= 10;
    }

    // Find the actual number
    long long number = start + (N - 1) / digits;

    // Find the digit inside the number
    string s = to_string(number);

    return s[(N - 1) % digits];
}

int main() {
    int N;
    cin >> N;
    char result = find_digit_at_position(N);
    cout << result << endl;
    return 0;
}