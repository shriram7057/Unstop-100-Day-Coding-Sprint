#include <iostream>
using namespace std;

struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : data(x), left(NULL), right(NULL) {}
};

TreeNode* insert(TreeNode* root, int key) {
    if (root == NULL) return new TreeNode(key);
    if (key < root->data) root->left = insert(root->left, key);
    else root->right = insert(root->right, key);
    return root;
}
int lowest_common_ancestor(TreeNode* root, int p, int q) {
    while (root) {
        if (p < root->data && q < root->data) {
            root = root->left;
        } else if (p > root->data && q > root->data) {
            root = root->right;
        } else {
            return root->data;
        }
    }
    return -1; // should never reach here if p and q exist
}
int main() {
    int n, x, y;
    cin >> n;
    TreeNode* root = NULL;
    for (int i = 0; i < n; i++) {
        int node;
        cin >> node;
        root = insert(root, node);
    }
    cin >> x >> y;
    int result = lowest_common_ancestor(root, x, y);
    cout << result << endl;
    return 0;
}