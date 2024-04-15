#
# @lc app=leetcode.cn id=617 lang=python
# @lcpr version=30122
#
# [617] 合并二叉树
#


# @lcpr-template-start

# @lcpr-template-end
# @lc code=start
# Definition for a binary tree node.
class TreeNode(object):
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class Solution(object):
    def dfs(self, root, r1, r2):
        # root是已经被创建了的
        # r1和r2中至少有一个非空
        assert not(r1 is None and r2 is None)

        if r1 is not None and r2 is not None:
            root.val = r1.val+r2.val
            if r1.left is not None or r2.left is not None:
                root.left = TreeNode()
                self.dfs(root.left, r1.left, r2.left)
            if r1.right is not None or r2.right is not None:
                root.right = TreeNode()
                self.dfs(root.right, r1.right, r2.right)
        elif r1 is not None:
            root.val = r1.val
            if r1.left is not None :
                root.left = TreeNode()
                self.dfs(root.left, r1.left, None)
            if r1.right is not None:
                root.right = TreeNode()
                self.dfs(root.right, r1.right, None)
        elif r2 is not None:
            root.val = r2.val
            if r2.left is not None :
                root.left = TreeNode()
                self.dfs(root.left, r2.left, None)
            if r2.right is not None:
                root.right = TreeNode()
                self.dfs(root.right, r2.right, None)
    # 上面的代码是完全不使用两个树的，如果使用非常好写，主要体现在对obj当一边是None时直接返回另一边

    def mergeTrees(self, root1, root2):
        """
        :type root1: TreeNode
        :type root2: TreeNode
        :rtype: TreeNode
        """
        if root1 is None:
            return root2
        
        if root2 is None:
            return root1
        
        root= TreeNode()
        self.dfs(root, root1, root2)

        return root
        
        
# @lc code=end



#
# @lcpr case=start
# [1,3,2,5]\n[2,1,3,null,4,null,7]\n
# @lcpr case=end

# @lcpr case=start
# [1]\n[1,2]\n
# @lcpr case=end

#

