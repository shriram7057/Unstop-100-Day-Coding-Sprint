#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node* next;
    Node(int data) {
        this->data = data;
        next = NULL;
    }
};

struct LinkedList {
    Node* head;
    Node* tail;
    LinkedList() {
        head = NULL;
        tail = NULL;
    }

    void print() {
        struct Node* temp = head;
        while (temp != NULL) {
            cout << temp->data << " ";
            temp = temp->next;
        }
    }

    void push(int data) {
        if (head == NULL) {
            Node* temp = new Node(data);
            head = temp;
            tail = temp;
        } else {
            Node* temp = new Node(data);
            tail->next = temp;
            tail = temp;
        }
    }
};
void reverseLinkedListUpToX(LinkedList& ll, int x) {
    Node* curr = ll.head;
    Node* prev = NULL;
    Node* nextNode = NULL;

    Node* originalHead = ll.head;

    bool found = false;

    // Reverse until x is found
    while (curr != NULL) {
        nextNode = curr->next;

        curr->next = prev;
        prev = curr;
        curr = nextNode;

        if (prev->data == x) {
            found = true;
            break;
        }
    }

    // Connect remaining list
    originalHead->next = curr;

    // Update head
    ll.head = prev;
}
int main() {
    LinkedList ll;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int t;
        cin >> t;
        ll.push(t);
    }
    int x;
    cin >> x;
    reverseLinkedListUpToX(ll, x);
    ll.print();
    return 0;
}