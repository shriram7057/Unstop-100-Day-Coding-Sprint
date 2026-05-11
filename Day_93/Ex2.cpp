
#include <iostream>
#include <vector>

#define MOD 998244353

int count_valid_ways(const std::vector<std::pair<int, int>>& cards) {
    // Write your logic here.
    // Parameters:
    //     cards: vector of pairs where each pair contains two integers (A_i, B_i)
    // Returns:
    //     Number of valid ways to flip the cards such that no two adjacent cards show the same number
    return 0;
}

int main() {
    int n;
    std::cin >> n;
    std::vector<std::pair<int, int>> cards(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> cards[i].first >> cards[i].second;
    }
    int result = count_valid_ways(cards);
    std::cout << result << std::endl;
    return 0;
}
