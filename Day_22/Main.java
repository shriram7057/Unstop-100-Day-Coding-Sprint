import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws Exception {
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        String line;
        while ((line = in.readLine()) != null) {
            TreeNode root = TreeNode.stringToTreeNode(line);
            TreeNode result = pruneTree(root);
            System.out.println(TreeNode.treeNodeToString(result));
        }
    }

    public static TreeNode pruneTree(TreeNode root) {
        if (root == null) {
            return null;
        }

        // Recursively prune left and right subtrees
        root.left = pruneTree(root.left);
        root.right = pruneTree(root.right);

        // If the current node is 0 and both left and right are null, remove this node
        if (root.val == 0 && root.left == null && root.right == null) {
            return null;
        }

        return root;
    }
}

class TreeNode {
    int val;
    TreeNode left;
    TreeNode right;

    TreeNode() {
        val = 0;
    }

    TreeNode(int x) {
        val = x;
    }

    public static TreeNode stringToTreeNode(String input) {
        input = input.trim();
        input = input.substring(1, input.length() - 1);
        if (input.length() == 0) {
            return null;
        }

        String[] parts = input.split(",");
        String item = parts[0];
        TreeNode root = new TreeNode(Integer.parseInt(item));
        Queue<TreeNode> nodeQueue = new LinkedList<>();
        nodeQueue.add(root);

        int index = 1;
        while (!nodeQueue.isEmpty()) {
            TreeNode node = nodeQueue.remove();

            if (index == parts.length) {
                break;
            }

            item = parts[index++];
            item = item.trim();
            if (!item.equals("null")) {
                int leftNumber = Integer.parseInt(item);
                node.left = new TreeNode(leftNumber);
                nodeQueue.add(node.left);
            }

            if (index == parts.length) {
                break;
            }

            item = parts[index++];
            item = item.trim();
            if (!item.equals("null")) {
                int rightNumber = Integer.parseInt(item);
                node.right = new TreeNode(rightNumber);
                nodeQueue.add(node.right);
            }
        }
        return root;
    }

    public static String treeNodeToString(TreeNode root) {
        if (root == null) {
            return "[]";
        }

        String output = "";
        Queue<TreeNode> nodeQueue = new LinkedList<>();
        nodeQueue.add(root);
        while (!nodeQueue.isEmpty()) {
            TreeNode node = nodeQueue.remove();

            if (node == null) {
                output += "null, ";
                continue;
            }

            output += String.valueOf(node.val) + ", ";
            nodeQueue.add(node.left);
            nodeQueue.add(node.right);
        }
        return "[" + output.substring(0, output.length() - 2) + "]";
    }
}