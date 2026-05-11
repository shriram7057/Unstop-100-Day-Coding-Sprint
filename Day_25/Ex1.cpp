#include <iostream>
#include <vector>
#include <algorithm>
struct Node {
    int val;
    Node* next;
    Node(int x) : val(x), next(nullptr) {}
};

int minChanges(Node* head, int n) {
    std::vector<int> original;
    original.reserve(n);

    Node* temp = head;

    // Store linked list values
    while (temp != nullptr) {
        original.push_back(temp->val);
        temp = temp->next;
    }

    // Create sorted version
    std::vector<int> sorted = original;
    std::sort(sorted.begin(), sorted.end());

    // Count mismatched positions
    int changes = 0;
    for (int i = 0; i < n; ++i) {
        if (original[i] != sorted[i]) {
            changes++;
        }
    }

    return changes;
}

int main() {
    int n;
    std::cin >> n;
    std::vector<int> values(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> values[i];
    }
    
    Node* head = new Node(values[0]);
    Node* temp = head;
    for (int i = 1; i < n; ++i) {
        temp->next = new Node(values[i]);
        temp = temp->next;
    }
    
    int result = minChanges(head, n);
    std::cout << result << std::endl;
    
    while (head != nullptr) {
        Node* next = head->next;
        delete head;
        head = next;
    }
    
    return 0;
}