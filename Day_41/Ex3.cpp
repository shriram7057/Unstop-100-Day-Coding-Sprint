#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

// Definition for a binary tree node
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// Helper function to perform DFS and delete nodes
TreeNode* dfs(TreeNode* node, unordered_set<int>& to_delete_set, vector<TreeNode*>& forest) {
    if (!node) return nullptr;

    // Traverse left and right children
    node->left = dfs(node->left, to_delete_set, forest);
    node->right = dfs(node->right, to_delete_set, forest);

    // If the current node is in to_delete set
    if (to_delete_set.count(node->val)) {
        // Add children to the forest if they are non-null
        if (node->left) forest.push_back(node->left);
        if (node->right) forest.push_back(node->right);
        return nullptr;  // Delete this node
    }

    return node;  // Keep this node
}

// Main function to delete nodes and return the forest
vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
    vector<TreeNode*> forest;
    unordered_set<int> to_delete_set(to_delete.begin(), to_delete.end());

    // Perform DFS to delete nodes
    if (dfs(root, to_delete_set, forest)) {
        forest.push_back(root);  // If root is not deleted, add it to the forest
    }

    return forest;
}

// Function to print the tree using inorder traversal
void printTree(TreeNode* root) {
    if (!root) return;
    printTree(root->left);
    cout << root->val << " ";
    printTree(root->right);
}

// Helper function to build a binary tree from level order input
TreeNode* buildTree(vector<int>& v1) {
    if (v1.empty() || v1[0] == -1) return nullptr;

    TreeNode* root = new TreeNode(v1[0]);
    vector<TreeNode*> nodes{root};
    int i = 1;

    while (i < v1.size()) {
        TreeNode* node = nodes.front();
        nodes.erase(nodes.begin());

        if (v1[i] != -1) {
            node->left = new TreeNode(v1[i]);
            nodes.push_back(node->left);
        }
        i++;

        if (i < v1.size() && v1[i] != -1) {
            node->right = new TreeNode(v1[i]);
            nodes.push_back(node->right);
        }
        i++;
    }

    return root;
}

int main() {
    // Reading input
    int n, m;
    cin >> n >> m;
    
    vector<int> v1(n);
    for (int i = 0; i < n; i++) cin >> v1[i];
    
    vector<int> to_delete(m);
    for (int i = 0; i < m; i++) cin >> to_delete[i];
    
    // Build the tree from the input array
    TreeNode* root = buildTree(v1);
    
    // Get the forest after deleting nodes
    vector<TreeNode*> forest = delNodes(root, to_delete);
    
    // Print the trees in the forest (inorder traversal)
    for (auto tree : forest) {
        printTree(tree);
        cout << endl;
    }

    return 0;
}