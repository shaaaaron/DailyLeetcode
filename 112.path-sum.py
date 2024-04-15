#
# @lc app=leetcode.cn id=112 lang=python
# @lcpr version=30122
#
# [112] 路径总和
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
    def dfs(self, root, pre_sum, targetSum):
        # 遍历到叶子节点而不是空节点
        now_sum = pre_sum + root.val
        if root.left is None and root.right is None:
            return now_sum == targetSum
        
        if root.left is not None:
            left_ans = self.dfs(root.left, now_sum, targetSum)
            if left_ans:
                return True
            
        if root.right is not None:
            right_ans = self.dfs(root.right, now_sum, targetSum)
            if right_ans:
                return True
        
        return False
        

    def hasPathSum(self, root, targetSum):
        """
        :type root: TreeNode
        :type targetSum: int
        :rtype: bool
        """
        if root is None:
            return False
        
        return self.dfs(root, 0, targetSum)
        
# @lc code=end



#
# @lcpr case=start
# []\n0\n
# @lcpr case=end

# @lcpr case=start
# [5,4,8,11,null,13,4,7,2,null,null,null,1]\n22\n
# @lcpr case=end

# @lcpr case=start
# [1,2,3]\n5\n
# @lcpr case=end

# @lcpr case=start
# []\n0\n
# @lcpr case=end

#

