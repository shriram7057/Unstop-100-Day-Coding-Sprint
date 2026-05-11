# Function to find X for each test case
def find_x(A, B, C):
    return A ^ (B & C)

# Input handling
T = int(input())
for _ in range(T):
    A, B, C = map(int, input().split())
    print(find_x(A, B, C))