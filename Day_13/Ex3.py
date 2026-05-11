def diagonal_sum(n):
    if n % 2 == 0:
        return 2 * n
    else:
        return 2 * n - 1

n = int(input())
print(diagonal_sum(n))