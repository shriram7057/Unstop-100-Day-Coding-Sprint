def user_logic(arr):
    stack = []
    total_sum = 0
    
    for num in arr:
        while stack and stack[-1] <= num:
            smallest = stack.pop()
            if stack:
                total_sum += smallest * min(stack[-1], num)
            else:
                total_sum += smallest * num
        stack.append(num)

    # Process remaining elements in the stack
    while len(stack) > 1:
        total_sum += stack.pop() * stack[-1]

    return total_sum

def main():
    import sys
    input = sys.stdin.read
    data = input().strip().split()
    
    n = int(data[0])  # First input is the integer N
    arr = list(map(int, data[1:]))  # Remaining input is the array of positive integers
    
    # Call user logic function and print the output
    result = user_logic(arr)
    print(result)

if __name__ == "__main__":
    main()