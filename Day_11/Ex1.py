def user_logic(n, arr):
    from collections import defaultdict
    
    # Function to get MSB position
    def msb(x):
        return x.bit_length() - 1
    
    groups = defaultdict(list)
    
    # Group numbers by MSB
    for num in arr:
        groups[msb(num)].append(num)
    
    count = 0
    
    # Check pairs within each group
    for g in groups.values():
        size = len(g)
        for i in range(size):
            for j in range(i + 1, size):
                a, b = g[i], g[j]
                if (a ^ b) <= (a & b):
                    count += 1
    
    return count


def main():
    import sys
    input = sys.stdin.read
    data = input().strip().split()
    
    n = int(data[0])
    arr = list(map(int, data[1:]))
    
    result = user_logic(n, arr)
    print(result)


if __name__ == "__main__":
    main()