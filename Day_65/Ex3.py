def count_filo_ways(n):
    count = 0
    two_n = 2 * n

    # Iterate through all k such that k * (2a + k - 1) = 2N
    k = 1
    while k * (k - 1) < 2 * n:
        if two_n % k == 0:
            temp = two_n // k - k + 1
            if temp % 2 == 0:
                a = temp // 2
                if a > 0:
                    count += 1
        k += 1

    return count

if __name__ == "__main__":
    n = int(input())
    result = count_filo_ways(n)
    print(result)