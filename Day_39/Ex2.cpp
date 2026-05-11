#include <iostream>

int special_series(int A, int B, int N) {
    if (N == 1)
        return A;

    if (N == 2)
        return B;

    int first = A;
    int second = B;
    int current;

    for (int i = 3; i <= N; i++) {
        current = abs(first - second);
        first = second;
        second = current;
    }

    return current;
}

int main() {
    int A, B, N;
    std::cin >> A >> B >> N;
    
    // Call user logic function and print the output
    int result = special_series(A, B, N);
    std::cout << result << std::endl;
    
    return 0;
}