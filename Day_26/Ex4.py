def special_stack_operations(capacity, queries):
    stack = []
    result = ["null"]  # Start with the initialization of the stack

    for query in queries:
        parts = query.split()
        
        if parts[0] == "push":
            # Push operation
            value = int(parts[1])
            if len(stack) < capacity:
                stack.append(value)
            result.append("null")
        
        elif parts[0] == "pop":
            # Pop operation
            if stack:
                result.append(str(stack.pop()))
            else:
                result.append("-1")
        
        elif parts[0] == "increment":
            # Increment operation
            k = int(parts[1])
            inc = int(parts[2])
            for i in range(min(k, len(stack))):
                stack[i] += inc
            result.append("null")

    return result

# Input reading and output handling
if __name__ == "__main__":
    capacity = int(input())  # Read the capacity of the stack
    q = int(input())  # Read the number of queries
    queries = [input().strip() for _ in range(q)]  # Read the queries
    
    result = special_stack_operations(capacity, queries)
    print(" ".join(result))