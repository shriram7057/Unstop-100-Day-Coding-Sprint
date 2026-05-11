#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <climits>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

TreeNode* recoverFromPreorder(const string& traversal) {
    stack<TreeNode*> st;
    int i = 0, n = traversal.size();

    while (i < n) {
        int depth = 0;
        while (i < n && traversal[i] == '-') {
            depth++;
            i++;
        }

        int value = 0;
        while (i < n && isdigit(traversal[i])) {
            value = value * 10 + (traversal[i] - '0');
            i++;
        }

        TreeNode* node = new TreeNode(value);

        while (st.size() > depth) {
            st.pop();
        }

        if (!st.empty()) {
            if (!st.top()->left)
                st.top()->left = node;
            else
                st.top()->right = node;
        }

        st.push(node);
    }

    while (st.size() > 1) st.pop();
    return st.top();
}

vector<int> user_logic(const string& traversal) {
    TreeNode* root = recoverFromPreorder(traversal);

    vector<int> result;
    vector<TreeNode*> q;
    q.push_back(root);

    while (!q.empty()) {
        TreeNode* curr = q.front();
        q.erase(q.begin());

        if (curr) {
            result.push_back(curr->val);
            q.push_back(curr->left);
            q.push_back(curr->right);
        } else {
            result.push_back(INT_MIN);
        }
    }

    return result;
}

int main() {
    string traversal;
    getline(cin, traversal);
    
    vector<int> result = user_logic(traversal);
    
    cout << "[";
    for (size_t i = 0; i < result.size(); ++i) {
        if (i > 0) cout << ", ";
        if (result[i] == INT_MIN) cout << "null";
        else cout << result[i];
    }
    cout << "]" << endl;

    return 0;
}