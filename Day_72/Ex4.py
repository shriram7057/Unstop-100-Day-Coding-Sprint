def minCostToMove(position):
    count_even = sum(1 for x in position if x % 2 == 0)
    count_odd = len(position) - count_even  # Rest are odd
    
    return min(count_even, count_odd)

# Input handling
n = int(input())  
position = list(map(int, input().split()))

# Output result
print(minCostToMove(position))