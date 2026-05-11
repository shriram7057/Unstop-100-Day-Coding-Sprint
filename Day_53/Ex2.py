import sys
from collections import defaultdict

def process_orders():
    # Read N and M
    N, M = map(int, sys.stdin.readline().split())

    # Dictionary to store orders for each table
    table_orders = defaultdict(list)

    # Read the M orders
    for _ in range(M):
        table, item = sys.stdin.readline().split()
        table_orders[int(table)].append(item)

    # Process and print the sorted orders for each table
    for i in range(N):
        print(" ".join(sorted(table_orders[i])))

# Execute function
process_orders()