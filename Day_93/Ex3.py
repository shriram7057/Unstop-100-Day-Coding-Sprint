import sys
input = sys.stdin.readline

MOD = 10**9 + 7

n, m = map(int, input().split())
adj = [[] for _ in range(n+1)]
indegree = [0]*(n+1)

for _ in range(m):
    u, v = map(int, input().split())
    adj[u].append(v)
    indegree[v] += 1

# Kahn's algorithm for topological sort
from collections import deque
q = deque()

for i in range(1, n+1):
    if indegree[i] == 0:
        q.append(i)

topo = []
while q:
    node = q.popleft()
    topo.append(node)
    for nei in adj[node]:
        indegree[nei] -= 1
        if indegree[nei] == 0:
            q.append(nei)

# DP to count paths
dp = [0]*(n+1)
dp[1] = 1

for node in topo:
    for nei in adj[node]:
        dp[nei] = (dp[nei] + dp[node]) % MOD

print(dp[n])