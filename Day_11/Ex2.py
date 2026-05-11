def calculate_total_cost(k, n, m, graph):
    # Count bulbs divisible by m (excluding 0)
    count = n // m
    return count * k


def main():
    import sys
    input = sys.stdin.read
    data = input().strip().split()
    
    k = int(data[0])
    n = int(data[1])
    m = int(data[2])
    len_graph = int(data[3])
    
    graph = []
    index = 4
    for _ in range(len_graph):
        u = int(data[index])
        v = int(data[index + 1])
        graph.append([u, v])
        index += 2
    
    total_cost = calculate_total_cost(k, n, m, graph)
    print(total_cost)


if __name__ == "__main__":
    main()