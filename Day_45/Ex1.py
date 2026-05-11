def another_permutation_problem(nums, K):
    """
    Write your logic here.
    Parameters:
        nums (list): List of integers
        K (int): An integer
    Returns:
        int: Computed result based on the problem statement
    """
    N = len(nums)
    target = nums[N-1]  # The value to be propagated

    # Find the leftmost occurrence of nums[N-1]
    p = -1
    for i in range(N):
        if nums[i] == target:
            p = i
            break  # Found the leftmost target occurrence

    # Calculate the number of operations needed
    remaining = p  # Number of elements to be covered
    if remaining == 0:
        return 0  # Already equal, no operations needed

    # Each step covers K-1 new elements (1 position overlaps)
    return (remaining + (K - 2)) // (K - 1)
    pass

def main():
    import sys
    input = sys.stdin.read
    data = input().strip().split()
    
    n = int(data[0])  # First input is the integer n
    nums = list(map(int, data[1:n+1]))  # Next n elements are the array of integers
    K = int(data[n+1])  # Last element is the integer K
    
    # Call user logic function and print the output
    result = another_permutation_problem(nums, K)
    print(result)

if __name__ == "__main__":
    main()