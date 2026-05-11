class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

# Function to build the perfect binary tree from level order traversal
def build_tree(level_order):
    if not level_order:
        return None

    root = TreeNode(level_order[0])
    queue = [root]
    index = 1

    while index < len(level_order):
        current = queue.pop(0)
        current.left = TreeNode(level_order[index])
        queue.append(current.left)
        index += 1

        if index < len(level_order):
            current.right = TreeNode(level_order[index])
            queue.append(current.right)
            index += 1

    return root

# Function to calculate the sum of all root-to-leaf paths
def sum_root_to_leaf(root, current_val=0):
    if not root:
        return 0

    current_val = (current_val << 1) | root.val

    # If it's a leaf node
    if not root.left and not root.right:
        return current_val

    # Recursively calculate for left and right subtrees
    return sum_root_to_leaf(root.left, current_val) + sum_root_to_leaf(root.right, current_val)

# Reading input
n = int(input().strip())
level_order = list(map(int, input().strip().split()))

# Building the tree
root = build_tree(level_order)

# Calculating the sum
result = sum_root_to_leaf(root)

# Printing the result
print(result)