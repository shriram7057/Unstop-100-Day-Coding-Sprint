#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* user_logic(Node* head, int k) {
    if (!head || k <= 0) return head; // If the list is empty or k is invalid, return as is.
    
    Node* new_head = nullptr;  // Head of the new linked list
    Node* new_tail = nullptr;  // Tail pointer for easy insertion
    
    Node* current = head;
    
    while (current) {
        int sum = 0, count = 0;
        Node* temp = current;
        
        // Traverse K nodes and calculate sum
        while (temp && count < k) {
            sum += temp->data;
            temp = temp->next;
            count++;
        }
        
        if (count == k) { // Only process when exactly K nodes are found
            int mean = sum / k;
            
            // If mean is even, insert into the new linked list
            if (mean % 2 == 0) {
                Node* new_node = new Node{mean, nullptr};
                if (!new_head) {
                    new_head = new_node;
                    new_tail = new_node;
                } else {
                    new_tail->next = new_node;
                    new_tail = new_node;
                }
            }
        } else { // Attach remaining elements as is it
            if (!new_head) {
                new_head = current;
            } else {
                new_tail->next = current;
            }
            break;
        }
        
        // Move current pointer forward by k nodes
        current = temp;
    }
    
    return new_head;
}

void print_list(Node* head) {
    Node* current = head;
    while (current != nullptr) {
        cout << current->data << " --> ";
        current = current->next;
    }
    cout << "null" << endl;
}

int main() {
    int k, n;
    cin >> k >> n;
    
    Node* head = nullptr;
    Node* tail = nullptr;
    
    for (int i = 0; i < n; ++i) {
        int data_value;
        cin >> data_value;
        Node* new_node = new Node{data_value, nullptr};
        if (head == nullptr) {
            head = new_node;
            tail = new_node;
        } else {
            tail->next = new_node;
            tail = new_node;
        }
    }
    
    // Call user logic function
    Node* modified_head = user_logic(head, k);
    
    // Print the resulting linked list
    print_list(modified_head);
    
    // Free allocated memory
    Node* current = modified_head;
    while (current != nullptr) {
        Node* temp = current;
        current = current->next;
        delete temp;
    }
    
    return 0;
}