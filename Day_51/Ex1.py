def min_deviation_after_insertion(N, Arr):
    # Compute initial MD
    MD = sum((Arr[i] - Arr[i-1])**2 for i in range(1, N))
    
    min_MD = float('inf')
    
    # Try inserting between each consecutive pair
    for i in range(1, N):
        a, b = Arr[i-1], Arr[i]
        original_cost = (b - a) ** 2
        
        # Try inserting floor((a+b)/2) and ceil((a+b)/2)
        for x in [(a + b) // 2, (a + b + 1) // 2]:
            new_cost = (x - a) ** 2 + (b - x) ** 2
            new_MD = MD - original_cost + new_cost
            min_MD = min(min_MD, new_MD)
    
    return min_MD

# Read input
N = int(input())
Arr = list(map(int, input().split()))

# Compute and print the result
print(min_deviation_after_insertion(N, Arr))