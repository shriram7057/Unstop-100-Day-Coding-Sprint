def solve():
    n, q = map(int, input().split())
    a = list(map(int, input().split()))
    
    # Prepare a 2D list for bit counts
    v = [[0] * (n + 1) for _ in range(61)]
    
    # Count bits
    for i in range(n):
        for j in range(61):
            v[j][i + 1] = v[j][i] + ((a[i] >> j) & 1)
    
    for _ in range(q):
        k, l1, r1, l2, r2 = map(int, input().split())
        l1 -= 1
        r1 -= 1
        l2 -= 1
        r2 -= 1
        
        s1 = v[k][r1 + 1] - v[k][l1]
        s2 = v[k][r2 + 1] - v[k][l2]
        
        u1 = (r1 - l1 + 1) - s1
        u2 = (r2 - l2 + 1) - s2
        
        print((s1 * u2) + (s2 * u1))

if __name__ == "__main__":
    T = int(input())
    for _ in range(T):
        solve()