def find_k_nearest_points(points, k):

    distances = []

    for index, point in enumerate(points):
        x, y = point
        dist = x * x + y * y
        distances.append((dist, index, point))

    distances.sort()

    result = []

    for i in range(k):
        result.append(distances[i][2])

    return result

def main():
    import sys
    input = sys.stdin.read
    data = input().strip().split()
    
    n = int(data[0])  # Number of points
    k = int(data[1])  # Number of nearest points to find
    
    points = []
    index = 2
    for _ in range(n):
        x = int(data[index])
        y = int(data[index + 1])
        points.append([x, y])
        index += 2
    
    # Call user logic function and get the result
    result = find_k_nearest_points(points, k)
    
    # Print the result
    for point in result:
        print(point[0], point[1])

if __name__ == "__main__":
    main()