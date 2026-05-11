import sys

MODULO = 10**9 + 7

# Class for a BST Node
class TreeNode:
    def __init__(self, val):
        self.val = val
        self.left = None
        self.right = None

# Function to insert nodes into a BST
def insert_bst(root, val):
    if not root:
        return TreeNode(val)
    if val < root.val:
        root.left = insert_bst(root.left, val)
    else:
        root.right = insert_bst(root.right, val)
    return root

# Convert Level Order Input to BST
def construct_bst_from_level_order(level_order):
    if not level_order or level_order[0] == -1:
        return None

    root = TreeNode(level_order[0])
    queue = [(root, 0)]

    i = 1
    while i < len(level_order):
        node, index = queue.pop(0)

        if level_order[i] != -1:
            node.left = TreeNode(level_order[i])
            queue.append((node.left, i))
        i += 1

        if i < len(level_order) and level_order[i] != -1:
            node.right = TreeNode(level_order[i])
            queue.append((node.right, i))
        i += 1

    return root

# Reverse Inorder Traversal to Modify Tree (Greater Sum Transformation)
def modify_bst(node, cumulative_sum):
    if not node:
        return cumulative_sum

    cumulative_sum = modify_bst(node.right, cumulative_sum)
    node.val += cumulative_sum
    cumulative_sum = node.val
    return modify_bst(node.left, cumulative_sum)

# Sum of All Nodes in BST
def sum_bst(node):
    if not node:
        return 0
    return (node.val + sum_bst(node.left) + sum_bst(node.right)) % MODULO

# Main function to read input, process BST and print result
def main():
    level_order = list(map(int, sys.stdin.readline().strip().split()))

    # Construct BST from level order
    root = construct_bst_from_level_order(level_order)

    # Apply Greater Sum Transformation
    modify_bst(root, 0)

    # Compute sum modulo (10^9 + 7)
    print(sum_bst(root))

# Execute the program
if __name__ == "__main__":
    main()