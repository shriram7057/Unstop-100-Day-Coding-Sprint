def can_reduce_to_zero(s):
    # Convert string to list of integers
    nums = list(map(int, s.split('-')))
    
    # Check necessary condition: sum must be even
    if sum(nums) % 2 != 0:
        print("NO")
        return

    # Check sufficient condition: max element ≤ sum of other two
    if max(nums) > sum(nums) - max(nums):
        print("NO")
        return
    
    print("YES")

# Read input
s = input().strip()

# Solve the problem
can_reduce_to_zero(s)