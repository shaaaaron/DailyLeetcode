#
# @lc app=leetcode.cn id=111 lang=python
# @lcpr version=30122
#
# [111] 二叉树的最小深度
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
    def minDepth(self, root):
        """
        :type root: TreeNode
        :rtype: int
        """
        # 最小深度不单纯是是最有的最小值，这点和最大深度不同
        if root is None:
            return 0
        
        if root.left is None and root.right is not None:
            return 1+self.minDepth(root.right)
        
        if root.left is not None and root.right is None:
            return 1+self.minDepth(root.left)
        
        return 1+min(self.minDepth(root.left), self.minDepth(root.right))
        # 如果左右两个节点相同，就直接计算
        
# @lc code=end



#
# @lcpr case=start
# [3,9,20,null,null,15,7]\n
# @lcpr case=end

# @lcpr case=start
# [2,null,3,null,4,null,5,null,6]\n
# @lcpr case=end

# @lcpr case=start
# [2,null,3,null,null]\n
# @lcpr case=end
#

