import sys

# Fast input reading
input = sys.stdin.read
sys.setrecursionlimit(10**6)

class SegmentTree:
    def __init__(self, arr):
        self.n = len(arr)
        self.tree = [0] * (4 * self.n)  # Segment tree
        self.build(arr, 0, 0, self.n - 1)

    def build(self, arr, node, start, end):
        if start == end:
            self.tree[node] = arr[start]
        else:
            mid = (start + end) // 2
            left_child = 2 * node + 1
            right_child = 2 * node + 2
            self.build(arr, left_child, start, mid)
            self.build(arr, right_child, mid + 1, end)
            self.tree[node] = max(self.tree[left_child], self.tree[right_child])

    def update(self, idx, value, node, start, end):
        if start == end:
            self.tree[node] = value
        else:
            mid = (start + end) // 2
            left_child = 2 * node + 1
            right_child = 2 * node + 2
            if idx <= mid:
                self.update(idx, value, left_child, start, mid)
            else:
                self.update(idx, value, right_child, mid + 1, end)
            self.tree[node] = max(self.tree[left_child], self.tree[right_child])

    def query(self, L, R, node, start, end):
        if R < start or end < L:
            return float('-inf')  # Out of range
        if L <= start and end <= R:
            return self.tree[node]  # Completely inside range
        mid = (start + end) // 2
        left_child = 2 * node + 1
        right_child = 2 * node + 2
        left_max = self.query(L, R, left_child, start, mid)
        right_max = self.query(L, R, right_child, mid + 1, end)
        return max(left_max, right_max)

def main():
    data = input().split()
    N = int(data[0])
    Q = int(data[1])
    
    arr = list(map(int, data[2:N+2]))
    queries = data[N+2:]
    
    seg_tree = SegmentTree(arr)
    result = []
    
    idx = 0
    for _ in range(Q):
        t = int(queries[idx])
        if t == 1:
            l = int(queries[idx+1])
            r = int(queries[idx+2])
            result.append(str(seg_tree.query(l, r, 0, 0, N - 1)))
            idx += 3
        elif t == 2:
            i = int(queries[idx+1])
            value = int(queries[idx+2])
            seg_tree.update(i, value, 0, 0, N - 1)
            idx += 3
    
    sys.stdout.write("\n".join(result) + "\n")

# Run the main function
if __name__ == "__main__":
    main()