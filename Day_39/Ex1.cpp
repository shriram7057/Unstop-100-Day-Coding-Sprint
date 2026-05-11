#include <iostream>

int user_logic(int N);

int main() {
    int N;
    std::cin >> N;
    int result = user_logic(N);
    std::cout << result << std::endl;
    return 0;
}

int user_logic(int N) {
    if (N == 0)
        return 0;

    if (N == 1)
        return 1;

    int paper1 = 0;
    int paper2 = 1;

    for (int i = 1; i < N; i++) {
        int sum = paper1 + paper2;
        paper1 = paper2;
        paper2 = sum;
    }

    return paper2;
}