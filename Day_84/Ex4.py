import bisect

def max_subarray_sum_modified_list(n, first_list, second_list):
    sorted_b = sorted(second_list)
    
    # Step 1: modify using bisect (correct handling)
    modified = []
    for x in first_list:
        idx = bisect.bisect_left(sorted_b, x)
        
        if idx < n and sorted_b[idx] == x:
            modified.append(sorted_b[(idx + 1) % n])
        else:
            modified.append(x)
    
    # Step 2: Kadane’s Algorithm
    max_sum = modified[0]
    curr_sum = modified[0]
    
    for i in range(1, n):
        curr_sum = max(modified[i], curr_sum + modified[i])
        max_sum = max(max_sum, curr_sum)
    
    return max_sum


def main():
    import sys
    data = sys.stdin.read().strip().split()
    
    n = int(data[0])
    first_list = list(map(int, data[1:n+1]))
    second_list = list(map(int, data[n+1:2*n+1]))
    
    print(max_subarray_sum_modified_list(n, first_list, second_list))


if __name__ == "__main__":
    main()