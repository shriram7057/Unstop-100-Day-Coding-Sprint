import math

def find_min_max_K(N, M, seats):
    # Maximum initial students in a seat
    max_initial = max(seats)
    
    # Maximum K: All M students sit on the max_initial seat
    max_K = max_initial + M
    
    # Minimum K: Distribute students as evenly as possible
    total_students = sum(seats) + M
    min_K = max(max_initial, math.ceil(total_students / N))
    
    print(min_K, max_K)

# Read input
N = int(input().strip())
M = int(input().strip())
seats = [int(input().strip()) for _ in range(N)]

# Solve the problem
find_min_max_K(N, M, seats)