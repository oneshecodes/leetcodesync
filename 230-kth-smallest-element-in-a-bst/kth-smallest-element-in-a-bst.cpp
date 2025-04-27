class Solution {
public:
    int count = 0;
    int result = -1;

    // Helper function for in-order traversal
    void inOrderTraversal(TreeNode* root, int k) {
        if (root == nullptr) {
            return;
        }

        // Traverse the left subtree
        inOrderTraversal(root->left, k);
        
        // Visit the current node
        count++;
        if (count == k) {
            result = root->val;
            return;
        }

        // Traverse the right subtree
        inOrderTraversal(root->right, k);
    }

    int kthSmallest(TreeNode* root, int k) {
        inOrderTraversal(root, k);
        return result;
    }
};
