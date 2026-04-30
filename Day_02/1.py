def calculate_pairs(n, arr):
    from collections import defaultdict
    import bisect

    # Prefix sum
    prefix = [0] * (n + 1)
    for i in range(n):
        prefix[i + 1] = prefix[i] + arr[i]

    # Map sum -> list of intervals (l, r)
    sums = defaultdict(list)

    # Generate all subarrays
    for r in range(1, n + 1):
        for l in range(1, r + 1):
            s = prefix[r] - prefix[l - 1]
            sums[s].append((l, r))

    total = 0

    # Process each sum group
    for intervals in sums.values():
        intervals.sort(key=lambda x: x[1])  # sort by end

        ends = []
        count = 0

        for l, r in intervals:
            # count intervals with end < l
            idx = bisect.bisect_left(ends, l)
            count += idx
            bisect.insort(ends, r)

        total += count

    return total


def main():
    import sys
    input = sys.stdin.read
    data = input().strip().split()
    n = int(data[0])
    arr = list(map(int, data[1:n+1]))
    print(calculate_pairs(n, arr))


if __name__ == "__main__":
    main()