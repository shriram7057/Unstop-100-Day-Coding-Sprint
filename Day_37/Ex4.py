# Constants
_ = 5000 + 10
__ = 10000 + 10

# Variables
e = 0
hd = [0] * _
nx = [0] * __
to = [0] * __
deg = [0] * _
q = [0] * _
a = [0] * _
p = [0] * _
l = r = m = 0

def add(u, v):
    global e
    e += 1
    nx[e] = hd[u]
    to[e] = v
    hd[u] = e
    deg[u] += 1

def main():
    global l, r, m
    n = int(input())
    
    for _ in range(1, n):
        u, v = map(int, input().split())
        add(u, v)
        add(v, u)
    
    l = 1
    r = 0
    for i in range(1, n + 1):
        if deg[i] == 1:
            r += 1
            q[r] = i
    
    while l <= r:
        u = q[l]
        l += 1
        m += 1
        a[m] = u
        
        i = hd[u]
        while i != 0:
            v = to[i]
            if deg[v] != 1:
                deg[v] -= 1
                if deg[v] == 1:
                    r += 1
                    q[r] = v
            i = nx[i]
    
    for i in range(1, n + 1):
        p[i] = i
    
    for i in range(2, n + 1, 2):
        u = a[i]
        v = a[i - 1]
        p[u], p[v] = p[v], p[u]
    
    print(" ".join(map(str, p[1:n+1])))

if __name__ == "__main__":
    main()