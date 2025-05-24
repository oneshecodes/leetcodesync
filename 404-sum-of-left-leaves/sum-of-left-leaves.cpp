
class Solution {
public:
    void helper(TreeNode* root, int& sum, bool onLeftSide) {
        if (root == NULL) return;

        if (root->left == NULL && root->right == NULL && onLeftSide) {
            sum += root->val;
            return;
        }

        helper(root->left, sum, true);   // Traverse left subtree
        helper(root->right, sum, false); // Traverse right subtree
    }

    int sumOfLeftLeaves(TreeNode* root) {
        int sum = 0;
        helper(root, sum, false);
        return sum;
    }
};