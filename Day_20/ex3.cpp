#include <iostream>
#include <vector>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* swapNodes(ListNode* head, int k) {
    ListNode* first = head;
    
    // Move to kth node from beginning
    for (int i = 1; i < k; i++) {
        first = first->next;
    }

    ListNode* kthFromStart = first;
    ListNode* second = head;

    // Find kth node from end
    while (first->next != NULL) {
        first = first->next;
        second = second->next;
    }

    // Swap values
    int temp = kthFromStart->val;
    kthFromStart->val = second->val;
    second->val = temp;

    return head;
}

int main() {
    int n, k;
    std::cin >> n;
    std::vector<int> values(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> values[i];
    }
    std::cin >> k;

    ListNode* dummy = new ListNode(0);
    ListNode* current = dummy;
    for (int value : values) {
        current->next = new ListNode(value);
        current = current->next;
    }
    ListNode* head = dummy->next;
    delete dummy;

    ListNode* modified_head = swapNodes(head, k);

    current = modified_head;
    while (current) {
        std::cout << current->val << " ";
        current = current->next;
    }
    std::cout << std::endl;

    return 0;
}