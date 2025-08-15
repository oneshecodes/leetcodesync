# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution(object):
    def pathSum(self, root, targetSum):
        """
        :type root: Optional[TreeNode]
        :type targetSum: int
        :rtype: List[List[int]]
        """
        def dfs(node, array):
            if not node:
                return 
            if not node.left and not node.right:
                if sum(array)==targetSum:
                    res.append(array)
                return
            if node.left:
                dfs(node.left,array+[node.left.val])
            if node.right: 
                dfs(node.right, array+[node.right.val])

        if not root:
            return []
        res=[]
        dfs(root, [root.val])
        return res