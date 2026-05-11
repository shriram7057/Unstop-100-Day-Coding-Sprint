#include <iostream>
#include <vector>
#include <algorithm>
std::vector<int> user_logic(const std::vector<int>& bst1_nodes, const std::vector<int>& bst2_nodes) {
    std::vector<int> result;

    // Add all elements from first BST
    for (int x : bst1_nodes) {
        result.push_back(x);
    }

    // Add all elements from second BST
    for (int x : bst2_nodes) {
        result.push_back(x);
    }

    // Sort the combined array
    std::sort(result.begin(), result.end());

    return result;
}
int main() {
    int N, M;
    std::cin >> N;
    std::vector<int> bst1_nodes(N);
    for (int i = 0; i < N; ++i) {
        std::cin >> bst1_nodes[i];
    }
    
    std::cin >> M;
    std::vector<int> bst2_nodes(M);
    for (int i = 0; i < M; ++i) {
        std::cin >> bst2_nodes[i];
    }
    
    std::vector<int> result = user_logic(bst1_nodes, bst2_nodes);
    
    for (const int& val : result) {
        std::cout << val << " ";
    }
    std::cout << std::endl;
    return 0;
}