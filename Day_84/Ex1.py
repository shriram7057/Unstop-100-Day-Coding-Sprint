def solve(arr):
    first = {}
    last = {}
    
    # Store first and last occurrence (1-based index)
    for i, val in enumerate(arr):
        if val not in first:
            first[val] = i + 1
        last[val] = i + 1
    
    # Build result
    res = []
    for val in arr:
        res.append(last[val] - first[val])
    
    return res


def main():
    import sys
    input = sys.stdin.read
    data = input().strip().split()
    
    n = int(data[0])
    arr = list(map(int, data[1:]))
    
    result = solve(arr)
    print(" ".join(map(str, result)))


if __name__ == "__main__":
    main()