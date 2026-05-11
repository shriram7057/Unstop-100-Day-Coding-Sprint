#include <iostream>
#include <queue>
#include <iomanip>
using namespace std;

int main() {
    int k;
    cin >> k;
    
    priority_queue<int> maxHeap; // To store the smaller half
    priority_queue<int, vector<int>, greater<int>> minHeap; // To store the larger half

    while (k--) {
        string query;
        cin >> query;

        if (query == "add") {
            int val;
            cin >> val;
            
            if (maxHeap.empty() || val <= maxHeap.top()) {
                maxHeap.push(val);
            } else {
                minHeap.push(val);
            }

            // Balancing both heaps to maintain the median
            if (maxHeap.size() > minHeap.size() + 1) {
                minHeap.push(maxHeap.top());
                maxHeap.pop();
            } else if (minHeap.size() > maxHeap.size()) {
                maxHeap.push(minHeap.top());
                minHeap.pop();
            }
        } else if (query == "get") {
            // Calculate median based on the size of heaps
            if (maxHeap.size() > minHeap.size()) {
                cout << fixed << setprecision(1) << (double)maxHeap.top() << endl;
            } else {
                cout << fixed << setprecision(1) << (double)(maxHeap.top() + minHeap.top()) / 2.0 << endl;
            }
        }
    }
    return 0;
}