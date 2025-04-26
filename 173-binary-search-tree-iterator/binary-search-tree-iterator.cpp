class BSTIterator {
    stack<TreeNode*> st;
    
    void pushAll(TreeNode* node) {
        while (node != nullptr) {
            st.push(node);
            node = node->left;
        }
    }
    
public:
    BSTIterator(TreeNode* root) {
        pushAll(root);
    }
    
    int next() {
        TreeNode* node = st.top();
        st.pop();
        if (node->right != nullptr) {
            pushAll(node->right);
        }
        return node->val;
    }
    
    bool hasNext() {
        return !st.empty();
    }
};
