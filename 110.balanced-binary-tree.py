#
# @lc app=leetcode.cn id=110 lang=python
# @lcpr version=30122
#
# [110] 平衡二叉树
#


# @lcpr-template-start

# @lcpr-template-end
# @lc code=start
# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution(object):
    def depth(self, root):  # 如果是平衡二叉树就返回深度，否则返回-1
        if root is None:
            return 0
        
        left_depth = self.depth(root.left)
        right_depth = self.depth(root.right)

        if left_depth == -1 or right_depth == -1:   # 如果左右子树中存在非平衡，则非平衡
            return -1

        if right_depth-left_depth>1 or right_depth-left_depth<-1:
            return -1

        return max(right_depth, left_depth)+1    


    def isBalanced(self, root):
        """
        :type root: TreeNode
        :rtype: bool
        """
        ans = self.depth(root)

        return False if ans==-1 else True
    
        
        
# @lc code=end



#
# @lcpr case=start
# [3,9,20,null,null,15,7]\n
# @lcpr case=end

# @lcpr case=start
# [1,2,2,3,3,null,null,4,4]\n
# @lcpr case=end

# @lcpr case=start
# []\n
# @lcpr case=end

#

