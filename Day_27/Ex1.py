class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None


def makeTree(idx, n, arr):
    if idx >= n or arr[idx] == -1:
        return None
    root = TreeNode(arr[idx])
    root.left = makeTree(2 * idx + 1, n, arr)
    root.right = makeTree(2 * idx + 2, n, arr)
    return root


def dfs(root, feq, count):
    if not root:
        return
    if not root.left and not root.right:
        feq[root.val] += 1
        odd = sum(1 for x in feq if x % 2 == 1)
        feq[root.val] -= 1
        if odd < 2:
            count[0] += 1
        return
    feq[root.val] += 1
    dfs(root.left, feq, count)
    dfs(root.right, feq, count)
    feq[root.val] -= 1


def countPalindromicPathways(n, arr):
    root = makeTree(0, n, arr)
    feq = [0] * 10
    count = [0]
    dfs(root, feq, count)
    return count[0]


if __name__ == "__main__":
    n = int(raw_input())
    arr = map(int, raw_input().split())
    result = countPalindromicPathways(n, arr)
    print(result)