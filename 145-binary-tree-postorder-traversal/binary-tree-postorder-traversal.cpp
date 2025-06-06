class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> result;
        if (!root) return result;

        stack<TreeNode*> st1, st2;
        st1.push(root);

        while (!st1.empty()) {
            TreeNode* curr = st1.top();
            st1.pop();
            st2.push(curr);

            if (curr->left) st1.push(curr->left);
            if (curr->right) st1.push(curr->right);
        }

        while (!st2.empty()) {
            result.push_back(st2.top()->val);
            st2.pop();
        }

        return result;
    }
};

