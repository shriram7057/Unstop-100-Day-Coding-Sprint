Node* user_logic(Node* head) {
    if (!head) return head;

    Node* curr = head;

    while (curr && curr->next) {
        if (curr->val == curr->next->val) {
            Node* temp = curr->next;
            curr->next = curr->next->next;
            delete temp;
        } else {
            curr = curr->next;
        }
    }

    return head;
}