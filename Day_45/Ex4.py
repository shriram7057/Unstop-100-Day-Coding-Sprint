from collections import deque

# **Binary Tree Node**
class TreeNode:
    def __init__(self, val=0):
        self.val = val
        self.left = None
        self.right = None

# **Function to Build a Complete Binary Tree**
def build_tree(sorted_nums):
    if not sorted_nums:
        return None

    root = TreeNode(sorted_nums[0])
    queue = deque([root])
    index = 1

    while index < len(sorted_nums):
        node = queue.popleft()

        # Assign left child
        if index < len(sorted_nums):
            node.left = TreeNode(sorted_nums[index])
            queue.append(node.left)
            index += 1
        
        # Assign right child
        if index < len(sorted_nums):
            node.right = TreeNode(sorted_nums[index])
            queue.append(node.right)
            index += 1

    return root

# **Function for Zigzag Level Order Traversal**
def zigzag_traversal(root):
    if not root:
        return []

    result = []
    queue = deque([root])
    left_to_right = True  # Direction flag

    while queue:
        level_size = len(queue)
        level_nodes = deque()

        for _ in range(level_size):
            node = queue.popleft()

            # Insert elements based on zigzag order
            if left_to_right:
                level_nodes.append(node.val)
            else:
                level_nodes.appendleft(node.val)

            if node.left:
                queue.append(node.left)
            if node.right:
                queue.append(node.right)

        result.append(list(level_nodes))
        left_to_right = not left_to_right  # Flip the direction

    return result

# **Reading Input**
n = int(input().strip())
arr = list(map(int, input().split()))

# **Sorting and Building Tree**
arr.sort()
root = build_tree(arr)

# **Perform Zigzag Traversal and Print Output**
output = zigzag_traversal(root)
for row in output:
    print(*row)