def validate_stack_sequences(pushed, popped):

    stack = []
    j = 0

    for num in pushed:
        stack.append(num)

        while stack and j < len(popped) and stack[-1] == popped[j]:
            stack.pop()
            j += 1

    if j == len(popped):
        return True, 0

    remaining = len(stack)

    def count_primes(n):
        count = 0

        for num in range(2, n + 1):
            prime = True

            for i in range(2, int(num ** 0.5) + 1):
                if num % i == 0:
                    prime = False
                    break

            if prime:
                count += 1

        return count

    prime_count = count_primes(remaining)

    return False, prime_count

def main():
    import sys
    input = sys.stdin.read
    data = input().strip().split()
    
    n = int(data[0])  # First input is the integer n
    pushed = list(map(int, data[1:n+1]))  # Next n integers are the pushed sequence
    popped = list(map(int, data[n+1:2*n+1]))  # Next n integers are the popped sequence
    
    # Call user logic function
    is_valid, prime_count = validate_stack_sequences(pushed, popped)
    
    # Print the output based on the returned values
    if is_valid:
        print("true")
    else:
        print("false")
        print(prime_count)

if __name__ == "__main__":
    main()