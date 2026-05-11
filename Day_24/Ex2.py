def count_expressible_numbers(X, Y):

    numbers = set()

    a = 1
    while a <= Y:

        b = 1
        while a * b <= Y:
            value = a * b

            if X <= value <= Y:
                numbers.add(value)

            b *= 3

        a *= 2

    return len(numbers)
def main():
    import sys
    input = sys.stdin.read
    data = input().strip().split()
    
    X = int(data[0])
    Y = int(data[1])
    
    # Call user logic function and print the output
    result = count_expressible_numbers(X, Y)
    print(result)

if __name__ == "__main__":
    main()