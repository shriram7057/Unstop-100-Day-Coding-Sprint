#include <iostream>
#include <vector>

void prime_matrix(int n, std::vector<std::vector<int>>& matrix) {
    /* Write your logic here. */
}

int main() {
    int n;
    std::cin >> n;
    std::vector<std::vector<int>> matrix(n, std::vector<int>(n));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            std::cin >> matrix[i][j];
        }
    }
    
    prime_matrix(n, matrix);
    
    for (const auto& row : matrix) {
        for (const auto& elem : row) {
            std::cout << elem << " ";
        }
        std::cout << std::endl;
    }
    return 0;
}