#include <bits/stdc++.h>
using namespace std;

#define INF INT_MAX
#define MOD 998244353
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL);

class SegmentTree {
public:
    vector<int> segTree;
    int n;

    SegmentTree(vector<int> &arr) {
        n = arr.size();
        segTree.resize(4 * n, INF);
        build(arr, 0, 0, n - 1);
    }

    void build(vector<int> &arr, int node, int start, int end) {
        if (start == end) {
            segTree[node] = arr[start];
        } else {
            int mid = (start + end) / 2;
            build(arr, 2 * node + 1, start, mid);
            build(arr, 2 * node + 2, mid + 1, end);
            segTree[node] = min(segTree[2 * node + 1], segTree[2 * node + 2]);
        }
    }

    void update(int index, int value, int node, int start, int end) {
        if (start == end) {
            segTree[node] = value;
        } else {
            int mid = (start + end) / 2;
            if (index <= mid)
                update(index, value, 2 * node + 1, start, mid);
            else
                update(index, value, 2 * node + 2, mid + 1, end);
            segTree[node] = min(segTree[2 * node + 1], segTree[2 * node + 2]);
        }
    }

    int query(int l, int r, int node, int start, int end) {
        if (r < start || l > end) return INF; // No overlap
        if (l <= start && end <= r) return segTree[node]; // Total overlap
        int mid = (start + end) / 2;
        return min(query(l, r, 2 * node + 1, start, mid),
                   query(l, r, 2 * node + 2, mid + 1, end));
    }
};

int main() {
    fastio;
    int N, Q;
    cin >> N >> Q;
    
    vector<int> arr(N);
    for (int i = 0; i < N; i++) cin >> arr[i];

    SegmentTree st(arr);

    while (Q--) {
        int type, x, y;
        cin >> type >> x >> y;
        if (type == 1) {
            // Convert to 0-based index and query the minimum
            cout << st.query(x - 1, y - 1, 0, 0, N - 1) << "\n";
        } else {
            // Convert to 0-based index and update value
            st.update(x - 1, y, 0, 0, N - 1);
        }
    }

    return 0;
}