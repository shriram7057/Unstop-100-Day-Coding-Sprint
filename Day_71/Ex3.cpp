#include <iostream>
#include <vector>
using namespace std;

// Definition of a linked list node
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

// Function to calculate the moving average
vector<double> movingAverage(ListNode* head, int K) {
    vector<double> result;
    if (!head || K <= 0) return result;

    ListNode* current = head;
    vector<int> window;
    int sum = 0;
    
    while (current) {
        window.push_back(current->val);
        sum += current->val;
        
        if (window.size() > K) {
            sum -= window.front(); // Remove the first element from sum
            window.erase(window.begin()); // Remove the first element from window
        }

        if (window.size() == K) {
            result.push_back((double)sum / K);
        }

        current = current->next;
    }
    
    return result;
}

int main() {
    int N, K;
    cin >> N;
    
    if (N == 0) {
        cout << endl;
        return 0;
    }

    // Creating the linked list
    int val;
    cin >> val;
    ListNode* head = new ListNode(val);
    ListNode* tail = head;

    for (int i = 1; i < N; i++) {
        cin >> val;
        tail->next = new ListNode(val);
        tail = tail->next;
    }

    cin >> K;
    
    vector<double> result = movingAverage(head, K);

    for (double avg : result) {
        cout << avg << " ";
    }
    cout << endl;

    return 0;
}