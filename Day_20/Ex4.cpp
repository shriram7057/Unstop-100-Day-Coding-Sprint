#include <iostream>
#include <unordered_map>
using namespace std;

struct Node {
    int val;
    Node* next;
    Node(int x) : val(x), next(nullptr) {}
};

int check(Node* l1, Node* l2) {
    Node* a = l1;
    Node* b = l2;

    while (a != b) {
        a = (a == nullptr) ? l2 : a->next;
        b = (b == nullptr) ? l1 : b->next;
    }

    return (a != nullptr) ? 1 : 0;
}
int main() {
    int n, m;
    cin >> n >> m;
    
    unordered_map<int, Node*> map;
    
    // Create first linked list
    Node* l1 = new Node(0);
    Node* temp = l1;
    for (int i = 0; i < n; i++) {
        int t;
        cin >> t;
        if (map.count(t)) {
            temp->next = map[t];
        } else {
            temp->next = new Node(t);
            map[t] = temp->next;
        }
        temp = temp->next;
    }
    l1 = l1->next;
    
    // Create second linked list
    Node* l2 = new Node(0);
    temp = l2;
    for (int i = 0; i < m; i++) {
        int t;
        cin >> t;
        if (map.count(t)) {
            temp->next = map[t];
        } else {
            temp->next = new Node(t);
            map[t] = temp->next;
        }
        temp = temp->next;
    }
    l2 = l2->next;
    
    // Call the user logic function
    int result = check(l1, l2);
    cout << result << endl;
    return 0;
}