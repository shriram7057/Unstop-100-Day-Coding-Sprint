import java.util.Scanner;

class TreeNode {
  int val;
  TreeNode left, right;

  TreeNode(int x) {
    val = x;
  }
}

public class Main {
  public static TreeNode insertIntoBST(TreeNode root, int val) {
    if (root == null)
      return new TreeNode(val);
    if (val <= root.val)
      root.left = insertIntoBST(root.left, val);
    else
      root.right = insertIntoBST(root.right, val);
    return root;
  }

  public static int sumOfValuesInRange(TreeNode root, int start, int end) {
    if (root == null)
      return 0;

    if (root.val < start) {
      return sumOfValuesInRange(root.right, start, end);
    }

    if (root.val > end) {
      return sumOfValuesInRange(root.left, start, end);
    }

    return root.val
        + sumOfValuesInRange(root.left, start, end)
        + sumOfValuesInRange(root.right, start, end);
  }

  public static void main(String[] args) {
    Scanner scanner = new Scanner(System.in);
    int n = scanner.nextInt();

    int[] values = new int[n];
    for (int i = 0; i < n; i++) {
      values[i] = scanner.nextInt();
    }

    int start = scanner.nextInt();
    int end = scanner.nextInt();

    TreeNode root = null;
    for (int val : values) {
      root = insertIntoBST(root, val);
    }

    int result = sumOfValuesInRange(root, start, end);
    System.out.println(result);
  }
}