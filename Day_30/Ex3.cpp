def max_modulo(L, R):
    if L == R:
        return 0
    if L > R // 2:
        return R % L
    else:
        return R % (R // 2 + 1)


T = int(input().strip())
results = []

for _ in range(T):
    L, R = map(int, input().strip().split())
    results.append(max_modulo(L, R))

for result in results:
    print(result)