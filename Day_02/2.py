import sys
input = sys.stdin.read

def can_print(s):
    r = s.count('R')
    b = s.count('B')
    return r == b and r > 0 or (r == b == 0)

data = input().split()
t = int(data[0])
idx = 1

res = []
for _ in range(t):
    n = int(data[idx]); idx += 1
    s = data[idx]; idx += 1
    if can_print(s):
        res.append("YES")
    else:
        res.append("NO")

print("\n".join(res))