def can_reach_home():
    # Read input values
    N, X, Y, Z = map(int, input().split())
    A = list(map(int, input().split()))
    
    # Calculate total time required
    total_time = sum(A) + (N * Y) + Z

    # Check if Lexi can reach home on time
    print("YES" if total_time <= X else "NO")

# Run the function
can_reach_home()