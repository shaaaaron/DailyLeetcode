#
# @lc app=leetcode.cn id=654 lang=python
# @lcpr version=30122
#
# [654] 最大二叉树
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
    def dfs(self, begin, end):
        if begin >= end:
            return None
        
        if begin+1 == end:
            return TreeNode(self.nums[begin])
        
        max_val_index = begin

        index = begin
        while index<end:
            if self.nums[index]> self.nums[max_val_index]:
                max_val_index = index
            index += 1

        root = TreeNode(self.nums[max_val_index])
        root.left = self.dfs(begin, max_val_index)  # 注意左闭右开不需要-1
        root.right = self.dfs(max_val_index+1, end)

        return root

    def constructMaximumBinaryTree(self, nums):
        """
        :type nums: List[int]
        :rtype: TreeNode
        """
        self.nums = nums

        root = self.dfs(0, len(nums))
        return root
# @lc code=end



#
# @lcpr case=start
# [3,2,1,6,0,5]\n
# @lcpr case=end

# @lcpr case=start
# [3,2,1]\n
# @lcpr case=end

#

