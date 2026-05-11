#include<bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// Function to create binary tree from given array and levels
TreeNode* create(vector<int> &arr, int level) {
    if (arr.size() <= 0 || level == 0) return nullptr;
    TreeNode *root = new TreeNode(arr[0]);
    vector<int> left, right;
    for (int i = 1; i <= arr.size() / 2; i++) {
        left.emplace_back(arr[i]);
    }
    for (int i = arr.size() / 2 + 1; i < arr.size(); i++) {
        right.emplace_back(arr[i]);
    }
    root->left = create(left, level - 1);
    root->right = create(right, level - 1);
    return root;
}

// Helper function to find max and min leaf values
void findLeafValues(TreeNode* root, int &minLeaf, int &maxLeaf) {
    if (!root) return;
    if (!root->left && !root->right) { // Check if the current node is a leaf
        minLeaf = min(minLeaf, root->val);
        maxLeaf = max(maxLeaf, root->val);
    }
    findLeafValues(root->left, minLeaf, maxLeaf);
    findLeafValues(root->right, minLeaf, maxLeaf);
}

// Function to calculate maximum absolute difference of leaf nodes
int maximumAbsDiff(TreeNode *root) {
    int minLeaf = INT_MAX, maxLeaf = INT_MIN;
    findLeafValues(root, minLeaf, maxLeaf);
    return abs(maxLeaf - minLeaf);
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int numberOfLevel;
        cin >> numberOfLevel;
        int numberOfNodes = pow(2, numberOfLevel) - 1;
        vector<int> arr(numberOfNodes);
        for (int i = 0; i < numberOfNodes; i++) cin >> arr[i];
        TreeNode *root = create(arr, numberOfLevel);
        cout << maximumAbsDiff(root) << "\n";
    }
}