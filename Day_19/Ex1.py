class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

def insertOrder(arr, i):
    # Base case for recursion
    if i >= len(arr) or arr[i] == "null":
        return None

    root = TreeNode(int(arr[i]))
    root.left = insertOrder(arr, 2 * i + 1)
    root.right = insertOrder(arr, 2 * i + 2)

    return root

def user_logic(root):
    from functools import lru_cache

    @lru_cache(None)
    def dfs(node):
        if not node:
            return (0, 0)  
        
        left = dfs(node.left)
        right = dfs(node.right)

        rob_this = node.val + left[1] + right[1]

        skip_this = max(left) + max(right)
        
        return (rob_this, skip_this)

    return max(dfs(root))

    pass

def main():
    import sys
    input = sys.stdin.read
    data = input().strip().split()
    
    # Build the tree from the input level-order traversal
    root = insertOrder(data, 0)
    
    # Call user logic function and print the output
    result = user_logic(root)
    print(result)

if __name__ == "__main__":
    main()