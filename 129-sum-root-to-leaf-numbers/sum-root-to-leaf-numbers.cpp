class Solution {
public:
    int sumNumbers(TreeNode* root) {
        return dfs(root, 0);  // Start DFS with the initial sum of 0
    }

private:
    int dfs(TreeNode* node, int currentSum) {
        if (!node) {
            return 0;  // Base case: if the node is null, return 0
        }
        
        // Update current sum (currentSum * 10 + current node value)
        currentSum = currentSum * 10 + node->val;
        
        // If it's a leaf node, return the current sum
        if (!node->left && !node->right) {
            return currentSum;
        }
        
        // Recursively call DFS on left and right children
        int leftSum = dfs(node->left, currentSum);
        int rightSum = dfs(node->right, currentSum);
        
        // Return the sum of left and right subtree
        return leftSum + rightSum;
    }
};

