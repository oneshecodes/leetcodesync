class Solution {
public:
    int countNodes(TreeNode* root) {
        if (!root) return 0;
        int left = 0, right = 0;
        TreeNode *l = root, *r = root;
        while (l) { left++; l = l->left; }
        while (r) { right++; r = r->right; }
        if (left == right) return (1 << left) - 1;
        return 1 + countNodes(root->left) + countNodes(root->right);
    }
};
