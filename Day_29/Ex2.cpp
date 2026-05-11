#include <iostream>

int colored_cells(int n) {
    if (n == 0)
        return 0;

    // Total triangles = 1 + 3 + 9 + ... + 3^(n-1)
    long long result = 0;
    long long power = 1;

    for (int i = 0; i < n; i++) {
        result += power;
        power *= 3;
    }

    return result;
}

int main() {
    int n;
    std::cin >> n;
    
    // Call user logic function and print the output
    int result = colored_cells(n);
    std::cout << result << std::endl;
    
    return 0;
}