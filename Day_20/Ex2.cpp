#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode* create_tree(vector<string>& data);
vector<int> left_view(TreeNode* root);

int main() {
    int n;
    cin >> n;
    vector<string> data(n);
    for (int i = 0; i < n; i++) {
        cin >> data[i];
    }
    TreeNode* root = create_tree(data);
    vector<int> result = left_view(root);
    for (int val : result) {
        cout << val << " ";
    }
    cout << endl;
    return 0;
}

TreeNode* create_tree(vector<string>& data) {
    if (data.empty() || data[0] == "N") {
        return NULL;
    }

    TreeNode* root = new TreeNode(stoi(data[0]));
    queue<TreeNode*> q;
    q.push(root);
    int i = 1;

    while (!q.empty() && i < data.size()) {
        TreeNode* current = q.front();
        q.pop();

        if (i < data.size() && data[i] != "N") {
            current->left = new TreeNode(stoi(data[i]));
            q.push(current->left);
        }
        i++;

        if (i < data.size() && data[i] != "N") {
            current->right = new TreeNode(stoi(data[i]));
            q.push(current->right);
        }
        i++;
    }

    return root;
}

vector<int> left_view(TreeNode* root) {
    vector<int> result;

    if (root == NULL)
        return result;

    queue<TreeNode*> q;
    q.push(root);

    while (!q.empty()) {
        int size = q.size();

        for (int i = 0; i < size; i++) {
            TreeNode* node = q.front();
            q.pop();

            // First node of each level
            if (i == 0) {
                result.push_back(node->val);
            }

            if (node->left)
                q.push(node->left);

            if (node->right)
                q.push(node->right);
        }
    }

    return result;
}