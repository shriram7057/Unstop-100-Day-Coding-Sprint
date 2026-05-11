def divide_gifts(N):
    total_sum = N * (N + 1) // 2

    # If the total sum is odd, partitioning is not possible
    if total_sum % 2 != 0:
        print("NO")
        return

    # Target sum for each subset
    target = total_sum // 2
    set1, set2 = [], []
    current_sum = 0

    # Use a greedy approach to fill set1 until target is reached
    for num in range(N, 0, -1):
        if current_sum + num <= target:
            set1.append(num)
            current_sum += num
        else:
            set2.append(num)

    # Print the results
    print("YES")
    print(len(set1))
    print(*set1)
    print(len(set2))
    print(*set2)

# Read input
N = int(input().strip())
divide_gifts(N)