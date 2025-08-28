
class Solution {
    ArrayList<Integer> list = new ArrayList<>();
    
    void inorder(TreeNode root) {
        
        if(root == null) return;
        inorder(root.left);
        list.add(root.val);
        inorder(root.right);
    }
    public boolean isValidBST(TreeNode root) {
        list.clear();
        inorder(root);
        
        for(int i = 0; i < list.size()-1; i++) {
            if(list.get(i) >= list.get(i+1)) {
                return false;
            }
        }
        return true;
    }
}