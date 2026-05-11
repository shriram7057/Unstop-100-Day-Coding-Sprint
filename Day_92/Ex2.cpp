#include <iostream>
#include <vector>
#include <stack>
using namespace std;

void monkeys_visible_from_each_pole(int n, vector<int> &heights) {
    vector<int> res(n, 0);
    stack<int> st; // monotonic decreasing stack (store indices)

    for (int i = n - 1; i >= 0; i--) {
        int count = 0;

        while (!st.empty() && heights[i] > heights[st.top()]) {
            st.pop();
            count++;
        }

        if (!st.empty()) {
            count++; // can see the next greater or equal pole
        }

        res[i] = count;
        st.push(i);
    }

    // overwrite input with result as expected by main()
    for (int i = 0; i < n; i++) {
        heights[i] = res[i];
    }
}

int main() {
    int n;
    cin >> n;

    vector<int> heights(n);
    for (int i = 0; i < n; ++i) {
        cin >> heights[i];
    }

    monkeys_visible_from_each_pole(n, heights);

    for (const auto &x : heights) {
        cout << x << ' ';
    }
    cout << '\n';

    return 0;
}