def user_logic(n):
    # Write your logic here
    return ~n & 0xFFFFFFFF  # Ensure 32-bit unsigned representation
    # return 0 # Placeholder return value

if __name__ == '__main__':
    n = int(input())
    result = user_logic(n)
    print(result)