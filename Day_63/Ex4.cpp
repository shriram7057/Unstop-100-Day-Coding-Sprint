#include <iostream>
#include <vector>

struct DoubleNode {
    int doubledata;
    DoubleNode* doubleprev;
    DoubleNode* doublenext;
    DoubleNode(int val) : doubledata(val), doubleprev(nullptr), doublenext(nullptr) {}
};

struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

DoubleNode* user_logic(int n, int m, const std::vector<std::vector<int>>& arr) {
    // Write your logic here
    return nullptr;
}

void print_double_linked_list(DoubleNode* head) {
    DoubleNode* current = head;
    while (current != nullptr) {
        std::cout << current->doubledata << " <---> ";
        current = current->doublenext;
    }
    std::cout << "null" << std::endl;
}

int main() {
    int n, m;
    std::cin >> n >> m;

    std::vector<std::vector<int>> arr(n, std::vector<int>(m));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            std::cin >> arr[i][j];
        }
    }

    DoubleNode* double_linked_list_head = user_logic(n, m, arr);
    print_double_linked_list(double_linked_list_head);

    return 0;
}