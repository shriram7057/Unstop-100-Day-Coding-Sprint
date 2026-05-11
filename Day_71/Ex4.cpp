#include <bits/stdc++.h>
using namespace std;

class TreeNode {
public:
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class LinkedListMultiplication {
public:
    static TreeNode* insertLevelOrder(vector<int>& arr, int i) {
        TreeNode* root = nullptr;
        if (i < arr.size()) {
            root = new TreeNode(arr[i]);
            root->left = insertLevelOrder(arr, 2 * i + 1);
            root->right = insertLevelOrder(arr, 2 * i + 2);
        }
        return root;
    }

    static long long convertBST(TreeNode* root) {
        vector<int> last_vis = {-1};
        vector<long long> ans = {0};
        dfs(root, last_vis, ans);
        return ans[0];
    }

    static void dfs(TreeNode* root, vector<int>& last_vis, vector<long long>& ans) {
        if (root == nullptr) return;
        dfs(root->left, last_vis, ans);
        if (root->val > last_vis[0]) {
            last_vis[0] = root->val;
        } else {
            ans[0] += last_vis[0] - root->val + 1;
            last_vis[0]++;
        }
        dfs(root->right, last_vis, ans);
    }
};

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
    TreeNode* root = LinkedListMultiplication::insertLevelOrder(arr, 0);
    cout << LinkedListMultiplication::convertBST(root) << endl;
    return 0;
}