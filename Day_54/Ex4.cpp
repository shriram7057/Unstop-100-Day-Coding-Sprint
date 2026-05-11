def largestRectangleArea(heights):
    stack = []
    max_area = 0
    n = len(heights)

    for i in range(n + 1):  
        while stack and (i == n or heights[i] < heights[stack[-1]]):
            h = heights[stack.pop()]  
            width = i if not stack else i - stack[-1] - 1  
            max_area = max(max_area, h * width)

        stack.append(i)

    return max_area


n = int(input())
heights = list(map(int, input().split()))

print(largestRectangleArea(heights))