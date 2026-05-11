#include <iostream>
#include <vector>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

int check_even_or_odd(ListNode* head) {
    if (!head) return 0;

    // Move to last node
    while (head->next != NULL) {
        head = head->next;
    }

    // Check last digit
    return (head->val % 2 == 0) ? 1 : 0;
}

int main() {
    int n;
    cin >> n;
    vector<int> elements(n);
    for (int i = 0; i < n; ++i) {
        cin >> elements[i];
    }

    ListNode* head = nullptr;
    if (n > 0) {
        head = new ListNode(elements[0]);
        ListNode* current = head;
        for (int i = 1; i < n; ++i) {
            current->next = new ListNode(elements[i]);
            current = current->next;
        }
    }

    int result = check_even_or_odd(head);
    cout << result << endl;

    return 0;
}